#include <eosio/eosio.hpp>

using namespace eosio;
using namespace std;

class [[eosio::contract]] quiz : public contract {
public:
   using contract::contract;

   [[eosio::action]]
   void set(string t);

   [[eosio::action]]
   void chapone(string as);

   [[eosio::action]]
   void chaptwo(string as);

   struct [[eosio::table]] info {
      name name;
      std::string answer;

      uint64_t primary_key()const { return name.value; }
      EOSLIB_SERIALIZE(info, (name)(answer));
   };
   typedef multi_index<"info"_n, info> infos;

};
