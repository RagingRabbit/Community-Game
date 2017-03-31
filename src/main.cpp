#include "Application.h"

#include <iostream>

#ifdef __WIN32
#include "windows.h"
#endif // __WIN32

namespace
{
    void errorMessage(const std::string& message)
    {
        #ifdef __WIN32
            MessageBox(nullptr, message.c_str(), "Error", MB_OK);
        #elif __linux
	    const std::string command = "zenity --error --text \"" + message + "\"";
	    system(command.c_str());
        #elif __APPLE__
	    const std::string command = "osascript -e 'tell app \"System Events\" to display dialog \"" + message + "\" buttons {\"OK\"} default button 1 with icon caution with title \"Error\"'";
	    system(command.c_str();
	#else
	    std::cerr << message << std::endl;
	    std::cin.ignore();
	#endif
    }
}

int main() try
{
    std::cout << "Anna test\n";

	Application app("Community Game", {800, 600, false, VSYNC_DISABLED});
	app.start();

	return EXIT_SUCCESS;
}
catch(std::out_of_range& e)
{
    std::string msg = e.what();
    errorMessage(msg);
    std::cin.ignore();
}
catch(std::runtime_error& e)
{
    std::string msg = e.what();
    errorMessage(msg);
    std::cin.ignore();
}
catch(...)
{
    errorMessage("Unknown error.");
    std::cin.ignore();
}


/*
This project is maintained by the  Community on Hopson97's Discord server.
The people who are currently working together on this are:
    KiddieD,
    Esscoder,byujh
    ans66f,
    DCubix,
    DarkCart,
    RagingRabbit,
    kaizi99,
    Pol_hp,
	Repertoi-e
*/
