#include <quiz/quiz.hpp>
#include <eosio/crypto.hpp>
#include <string>

template<typename CharT>
static std::string to_hex( const CharT* d, uint32_t s ) {
    std::string r;
    const char* to_hex="0123456789abcdef";
    uint8_t* c = (uint8_t*)d;
    for( uint32_t i = 0; i < s; ++i ) {
        (r += to_hex[(c[i] >> 4)]) += to_hex[(c[i] & 0x0f)];
    }
return r;
}

void quiz::set(string t) {
   auto hash = eosio::sha256(reinterpret_cast<const char*>(t.data()), t.size());
   auto data = hash.extract_as_byte_array();
   printhex(&data, data.size());
}

void quiz::chapone(string ansr) {
   require_auth(_self);
   std::string shash = "a608cabd9188bee422c32f81183da2bfc42cbc135d9d131fdcbdeb473e2fbade";

   infos idx(_self, _self.value);

   auto hash = eosio::sha256(reinterpret_cast<const char*>(ansr.data()), ansr.size());
   auto bytes = hash.extract_as_byte_array();
   auto data = to_hex(bytes.data(), bytes.size());

   check(shash.compare(data) == 0, "try again");
   idx.emplace(_self, [&](auto& n){
         n.name = "chapone"_n;
         n.answer = ansr;
   });

   print(ansr," you for being by my side");
}

void quiz::chaptwo(string ansr) {
   require_auth(_self);
   std::string shash = "489f719cadf919094ddb38e7654de153ac33c02febb5de91e5345cbe372cf4a0";

   infos idx(_self, _self.value);
   auto it = idx.find("chapone"_n.value);

   check(it != idx.end(), "the chapone was not solved");

   auto hash = eosio::sha256(reinterpret_cast<const char*>(ansr.data()), ansr.size());
   auto bytes = hash.extract_as_byte_array();
   auto data = to_hex(bytes.data(), bytes.size());

   check(shash.compare(data) == 0, "try again");

   idx.emplace(_self, [&](auto& n){
         n.name = "chaptwo"_n;
         n.answer = ansr;
   });
   print("I hope you are all ", ansr);
}
