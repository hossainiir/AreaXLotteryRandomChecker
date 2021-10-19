#include "rngchecker.hpp"

name ACTIVE = "active"_n;

void rngchecker::chcklottrng(checksum256 random,uint64_t last_ticket_id){
  auto rnd = random.get_array()[1];
  auto winner_ticket =((uint64_t) (rnd % last_ticket_id))+1;
  auto str = std::string("Ticket id : ")+std::to_string(winner_ticket);

  eosio::action(
      permission_level{ _self , ACTIVE },
      _self, "log"_n,
      std::make_tuple(std::string(str))
  ).send();
}

void rngchecker::log(std::string str){
  require_auth(_self);
}