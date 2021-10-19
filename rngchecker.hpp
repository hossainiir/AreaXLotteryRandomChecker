#include <string>
#include <eosio/eosio.hpp>
#include <eosio/print.hpp>
#include <eosio/transaction.hpp>
#include <eosio/system.hpp>

using namespace eosio;

using eosio::permission_level;
using eosio::action;
using eosio::name;

using std::string;

class [[eosio::contract("rngchecker")]] rngchecker : public contract {
  public:
    using contract::contract;
    rngchecker(name receiver, name code, datastream<const char*> ds):
    contract(receiver, code, ds){
    }

    //common
    ACTION chcklottrng(checksum256 random,uint64_t last_ticket_id);

    ACTION log(std::string str);
};
