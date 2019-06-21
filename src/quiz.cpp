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

void quiz::chapone(string t) {
   std::string shash = "489f719cadf919094ddb38e7654de153ac33c02febb5de91e5345cbe372cf4a0";

   auto hash = eosio::sha256(reinterpret_cast<const char*>(t.data()), t.size());
   auto data = to_hex(hash.data(), hash.size());

   check(shash.compare(data), "got-chya got-chya");
   print("I hope you are all ", t);
}
