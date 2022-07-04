// sleep.cpp : Defines the entry point for the application.
//

#include "sleep.h"

using namespace std;

int main(int argc, char *argv[])
{
	string help = "This program only supports one parameter, the time to sleep in seconds as an positive `long long`!";
	if (argc != 2) {
		cout << "This program only takes one argument!" << endl;
		cout << help << endl;
		return 1;
	}

	try {
		size_t parsedChars = 0;
		long long sleep_seconds = stol(argv[1], &parsedChars);
		if (strlen(argv[1]) != parsedChars) {
			cout << "Not a propper `long long` as time in seconds to wait! Maybe you added some characters after a proper `long long`?" << endl;			
			return 1;
		}
		if(sleep_seconds < 0) {
			cout << "Not a propper positive `long long` as time in seconds to wait!" << endl;			
			return 1;
		}
				
		typedef std::chrono::duration<long long> seconds_type;		
		seconds_type sleep_duration(sleep_seconds);		
		this_thread::sleep_for(sleep_duration);		

		
		
	}
	catch (invalid_argument ia_err) {
		cout << "The given argument is not in a valid form!" << endl;
		cout << help << endl;
		return 1;
	}
	catch (out_of_range oor_err) {
		cout << "The given number is to big!" << endl;
		cout << help << endl;
		return 1;
	}

	return 0;
}
