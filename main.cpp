//
// Created by nomenas on 02-04-20.
//

#include "server_protos/MyService.pb.h"

#include <string>

#include <tao/json.hpp>

struct Message {
  std::string string_value;
  int number_value;
};

void ConvertToCObject(const tao::json::value& json) {
  Message message;
  message.string_value = json.as<std::string>("string");
  message.number_value = json.as<int>("number");

//  std::cout << message.number_value << ": " << message.string_value.substr(0, 10) << std::endl;
};

void ConvertToProtoAndThenToCObject(const tao::json::value& json) {
  server::Message proto_message;
  proto_message.set_string(json.as<std::string>("string"));
  proto_message.set_number(json.as<int>("number"));

  Message message;
  message.string_value = proto_message.string();
  message.number_value = proto_message.number();

//  std::cout << message.number_value << ": " << message.string_value.substr(0, 10) << std::endl;
};

int main(int argc, char** argv) {
  tao::json::value json_object = {
      {"string", std::string(1024, '0')}
  };

  auto megabytes_to_be_converted = 100;
  for (int i = 0; i < 1000 * megabytes_to_be_converted; ++i) {
    json_object["number"] = i;
    ConvertToCObject(json_object);
  }

  return 0;
}