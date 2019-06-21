#include <eosio/eosio.hpp>

using namespace eosio;
using namespace std;

class [[eosio::contract]] quiz : public contract {
public:
   using contract::contract;

   [[eosio::action]]
   void set(string t);

   [[eosio::action]]
   void chapone(string t);
};
