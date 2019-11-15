#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <functional>
#include <string>
#include<iostream>
#include "HashMap.hpp"



class Commands
{
public:
	Commands();

private:
	unsigned int debug, finish;
	std::string command, com, username, password;
	HashMap hm;

	void inputs();
	std::string get_inf(std::string& command);
	void handle_inputs();

	void handle_debug();
	void handle_bucket_count();
	void handle_load_factor();
	void handle_bucket_size();
	void handle_create();
    void handle_login();
	void handle_remove();
	void handle_clear();
	void handle_quit();
    void handle_invalid_input();

};

#endif