#include "commands.hpp"

Commands::Commands()
        :debug{0}, finish{0}, command{""}, com{""}, username{""}, password{""}, hm{HashMap()}
{
	while (finish != 1)
	{
		command = "";
		com = "";
		username = "";
		password = "";
		inputs();
	}
}

void Commands::inputs()
{
	std::getline(std::cin, command);
	command.erase(0,command.find_first_not_of(" "));
	command.erase(command.find_last_not_of(" ")+1);
	com = command.substr(0,command.find(" "));
	if (command.find(" ") != command.npos)
	{
	    username = get_inf(command);
	    if (command.find(" ") != command.npos)
	    {
	    	password = get_inf(command);
        }
    }
    handle_inputs();
}

std::string Commands::get_inf(std::string& command)
{
	command = command.substr(command.find(" "),-1);
   	command.erase(0,command.find_first_not_of(" "));
  	command.erase(command.find_last_not_of(" ")+1);
    return command.substr(0,command.find(" "));
}

void Commands::handle_inputs()
{
	if (com == "DEBUG")
	{
		handle_debug();
	}
	else if (com == "BUCKET" and username == "COUNT" and password == "")
	{
		handle_bucket_count();
	}
	else if (com == "LOAD" and username == "FACTOR" and password == "")
	{
		handle_load_factor();
	}
	else if (com == "MAX" and username == "BUCKET" and password == "SIZE")
	{
		handle_bucket_size();
	}
    else if (com == "CREATE" and username != "" and password != "")
    {
    	handle_create();
    }
	else if (com == "LOGIN")
	{
		handle_login();
	}
	else if (com == "REMOVE" and username != "" and password == "")
	{
		handle_remove();
	}
	else if (com == "CLEAR" and username == "" and password == "")
	{
		handle_clear();
	}
    else if (com == "QUIT" and username == "" and password == "")
    {
    	handle_quit();
    }
	else
	{
		handle_invalid_input();
	}


}

void Commands::handle_debug()
{
	if (username == "ON" and password == "")
	{
		if (debug==0)
		{
			std::cout << "ON NOW" << std::endl;
			debug = 1;
		}
		else
		{
			std::cout << "ON ALREADY" << std::endl;
		}
	}
	else if (username == "OFF" and password == "")
	{
		if (debug==0)
		{
			std::cout << "OFF ALREADY" << std::endl;
		}
		else
		{
			std::cout << "OFF NOW" << std::endl;
			debug = 0;
		}
	}
	else
	{
		std::cout << "INVALID" << std::endl;
	}	
}


void Commands::handle_bucket_count()
{
	if (debug == 1)
	{
		std::cout << hm.bucketCount() << std::endl;
	}
	else
	{
		std::cout << "INVALID" << std::endl;
	}
}

void Commands::handle_load_factor()
{
	if (debug == 1)
	{
		std::cout << hm.loadFactor() << std::endl;
	}
	else
	{
		std::cout << "INVALID" << std::endl;
	}
}

void Commands::handle_bucket_size()
{
	if (debug == 1)
	{
		std::cout << hm.maxBucketSize() << std::endl;
	}
	else
	{
		std::cout << "INVALID" << std::endl;
	}
}

void Commands::handle_create()
{
	if (hm.contains(username)==false)
	{
		std::cout << "CREATED" << std::endl;
      	hm.add(username,password);
   	}
    else
    {
  		std::cout << "EXISTS" << std::endl;
    }
}

void Commands::handle_login()
{
	if (username == "COUNT" and password == "")
	{
		if (debug == 1)
	    {
	    	std::cout << hm.size() << std::endl;
	    }
	    else
   		{
   			std::cout << "INVALID" << std::endl;
   		}
   	}
   	else if (username != "" and password != "")
   	{
   		if (hm.contains(username)==true and password == hm.value(username))
   		{
   			std::cout << "SUCCEEDED" << std::endl;
   		}
   		else
   		{
    		std::cout << "FAILED" << std::endl;
    	}
    }
    else
    {
    	std::cout << "INVALID" << std::endl;
    }
}

void Commands::handle_remove()
{
	if (hm.contains(username)==false)
	{
		std::cout << "NONEXISTENT" << std::endl;
	}
	else
	{
		hm.remove(username);
		std::cout << "REMOVED" << std::endl;
	}
}

void Commands::handle_clear()
{
	hm.clear();
}

void Commands::handle_quit()
{
	std::cout << "GOODBYE" << std::endl;
	finish = 1;
}

void Commands::handle_invalid_input()
{
	std::cout << "INVALID" << std::endl;
}
	
