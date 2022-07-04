// sleep.cpp : Defines the entry point for the application.
//

#include "sleep.h"

using namespace std;

int main(int argc, char *argv[])
{
	string help = "This program only supports one parameter, the time to sleep in seconds as an `unsigned long long`!";
	if (argc != 2) {
		cout << "This program only takes one argument!" << endl;
		cout << help << endl;
		return 1;
	}

	try {
		size_t parsedChars = 0;
		unsigned long long sleep_seconds = stoull(argv[1], &parsedChars);
		if (strlen(argv[1]) != parsedChars) {
			cout << "Not a propper unsigned long long as time in seconds to wait!" << endl;
			cout << help << endl;
			return 1;
		}
		cout << "Sleeping for: " << sleep_seconds << " seconds!" << endl;
		// sleep here ?
		typedef std::chrono::duration<int> seconds_type;
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
