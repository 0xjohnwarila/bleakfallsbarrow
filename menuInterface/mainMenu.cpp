#include <iostream>
#include "../saveGame/save.h"
#include "../global/globalFunk.h"
#include "../menuInterface/mainMenu.h"

void printTitleScreen(){
	using std::cout;
	using std::endl;
	cout << "\033[2J\033[1;1H";
	cout << endl << endl << endl;
	cout << " ______   _        _______  _______  _          _______  _______  _        _        _______    ______   _______  _______  _______  _______          " << endl;
	cout << "(  ___ \\ ( \\      (  ____ \\(  ___  )| \\    /\\  (  ____ \\(  ___  )( \\      ( \\      (  ____ \\  (  ___ \\ (  ___  )(  ____ )(  ____ )(  ___  )|\\     /|" << endl;
	cout << "| (   ) )| (      | (    \\/| (   ) ||  \\  / /  | (    \\/| (   ) || (      | (      | (    \\/  | (   ) )| (   ) || (    )|| (    )|| (   ) || )   ( |" << endl;
	cout << "| (__/ / | |      | (__    | (___) ||  (_/ /   | (__    | (___) || |      | |      | (_____   | (__/ / | (___) || (____)|| (____)|| |   | || | _ | |" << endl;
	cout << "|  __ (  | |      |  __)   |  ___  ||   _ (    |  __)   |  ___  || |      | |      (_____  )  |  __ (  |  ___  ||     __)|     __)| |   | || |( )| |" << endl;
	cout << "| (  \\ \\ | |      | (      | (   ) ||  ( \\ \\   | (      | (   ) || |      | |            ) |  | (  \\ \\ | (   ) || (\\ (   | (\\ (   | |   | || || || |" << endl;
	cout << "| )___) )| (____/\\| (____/\\| )   ( ||  /  \\ \\  | )      | )   ( || (____/\\| (____/\\/\\____) |  | )___) )| )   ( || ) \\ \\__| ) \\ \\__| (___) || () () |" << endl;
	cout << "|/ \\___/ (_______/(_______/|/     \\||_/    \\/  |/       |/     \\|(_______/(_______/\\_______)  |/ \\___/ |/     \\||/   \\__/|/   \\__/(_______)(_______)" << endl;
	cout << "                                             /\\                                                 /\\" << "\n";
	cout << "                                   _         )( _______________________ _______________________ )(         _" << "\n";
	cout << "                                  (_)///////(**)______________________/ \\______________________(**)\\\\\\\\\\\\\\(_)" << "\n";
	cout << "                                             )(                                                 )(" << "\n";
	cout << "                                             \\/                                                 \\/" << "\n";

	cout << endl << endl;
	cout << "                      _                                                                           _                                                      \n";
	cout << "                     /#\\                                                                         /#\\                                                    \n";
	cout << "                    /###\\     /\\                                                                /###\\     /\\                                           \n";
	cout << "                   /  ###\\   /##\\  /\\                                                          /  ###\\   /##\\  /\\                                     \n";
	cout << "                  /      #\\ /####\\/##\\                                                        /      #\\ /####\\/##\\                                    \n";
	cout << "                 /  /      /   # /  ##\\             _       /\\                               /  /      /   # /  ##\\             _       /\\             \n";
	cout << "               // //  /\\  /    _/  /  #\\ _         /#\\    _/##\\    /\\                      // //  /\\  /    _/  /  #\\ _         /#\\    _/##\\    /\\   \n";
	cout << "              // /   /  \\     /   /    #\\ \\      _/###\\_ /   ##\\__/ _\\                    // /   /  \\     /   /    #\\ \\      _/###\\_ /   ##\\__/ _\\ \n";
	cout << "             /  \\   / .. \\   / /   _   { \\ \\   _/       / //    /     \\                  /  \\   / .. \\   / /   _   { \\ \\   _/       / //    /     \\  \n";
	cout << "     /\\     /    /\\  ...  \\_/   / / \\   } \\ | /  /\\  \\ /  _    /  /    \\/\\       /\\     /    /\\  ...  \\_/   / / \\   } \\ | /  /\\  \\ /  _    /  /    \\/\\\n";
	cout << "  _ /  \\  /// / .\\  ..%:.  /... /\\ . \\ {:  \\   /. \\     / \\  /   ___   /  \\   _ /  \\  /// / .\\  ..%:.  /... /\\ . \\ {:  \\   /. \\     / \\  /   ___   /  \\\n";
	cout << " /.\\ .\\.\\// \\/... \\.::::..... _/..\\ ..\\:|:. .  / .. \\  /.. \\    /...\\ /  \\ \\ /.\\ .\\.\\// \\/... \\.::::..... _/..\\ ..\\:|:. .  / .. \\  /.. \\    /...\\ /  \\ \\\n";
	cout << "/...\\.../..:.\\. ..:::::::..:..... . ...\\{:... / %... \\/..%. \\  /./:..\\__    \\/...\\.../..:.\\. ..:::::::..:..... . ...\\{:... / %... \\/..%. \\  /./:..\\__    \\\n";
	cout << " .:..\\:..:::....:::;;;;;;::::::::.:::::.\\}.....::%.:. \\ .:::. \\/.%:::.:..\\ .:..\\:..:::....:::;;;;;;::::::::.:::::.\\}.....::%.:. \\ .:::. \\/.%:::.:..\\\n";
	cout << "::::...:::;;:::::;;;;;;;;;;;;;;:::::;;::{:::::::;;;:..  .:;:... ::;;::::..::::...:::;;:::::;;;;;;;;;;;;;;:::::;;::{:::::::;;;:..  .:;:... ::;;::::..\n";
	cout << ";;;;:::;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;];;;;;;;;;;::::::;;;;:.::;;;;;;;;:..;;;;:::;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;];;;;;;;;;;::::::;;;;:.::;;;;;;;;:..\n";
	cout << ";;;;;;;;;;;;;;ii;;;;;;;;;;;;;;;;;;;;;;;;[;;;;;;;;;;;;;;;;;;;;;;:;;;;;;;;;;;;;;;;;;;;;;;;;;;ii;;;;;;;;;;;;;;;;;;;;;;;;[;;;;;;;;;;;;;;;;;;;;;;:;;;;;;;;;;;;;\n";
	cout << ";;;;;;;;;;;;;;;;;;;iiiiiiii;;;;;;;;;;;;;;};;ii;;iiii;;;;i;;;;;;;;;;;;;;;ii;;;;;;;;;;;;;;;;;;;;;;iiiiiiii;;;;;;;;;;;;;;};;ii;;iiii;;;;i;;;;;;;;;;;;;;;ii;;;\n";
	cout << "iiii;;;iiiiiiiiiiIIIIIIIIIIIiiiiiIiiiiii{iiIIiiiiiiiiiiiiiiii;;;;;iiiilliiiiiiiii;;;iiiiiiiiiiIIIIIIIIIIIiiiiiIiiiiii{iiIIiiiiiiiiiiiiiiii;;;;;iiiilliiiii\n";
	cout << "IIIiiIIllllllIIlllIIIIlllIIIlIiiIIIIIIIIIIIIlIIIIIllIIIIIIIIiiiiiiiillIIIllIIIIIiiIIllllllIIlllIIIIlllIIIlIiiIIIIIIIIIIIIlIIIIIllIIIIIIIIiiiiiiiillIIIllII\n";
	cout << "IIIiiilIIIIIIIllTIIIIllIIlIlIIITTTTlIlIlIIIlIITTTTTTTIIIIlIIllIlIlllIIIIIIITTIIIiiilIIIIIIIllTIIIIllIIlIlIIITTTTlIlIlIIIlIITTTTTTTIIIIlIIllIlIlllIIIIIIITT\n";
	cout << "IIIIilIIIIITTTTTTTIIIIIIIIIIIIITTTTTIIIIIIIIITTTTTTTTTTIIIIIIIIIlIIIIIIIITTTTIIIIilIIIIITTTTTTTIIIIIIIIIIIIITTTTTIIIIIIIIITTTTTTTTTTIIIIIIIIIlIIIIIIIITTTT\n";
	cout << "IIIIIIIIITTTTTTTTTTTTTIIIIIIIITTTTTTTTIIIIIITTTTTTTTTTTTTTIIIIIIIIIIIIIITTTTTIIIIIIIIITTTTTTTTTTTTTIIIIIIIITTTTTTTTIIIIIITTTTTTTTTTTTTTIIIIIIIIIIIIIITTTTT\n";
	sleepMilli(2500);
	cout << "\033[2J\033[1;1H";
	credits();
	sleepMilli(1500);
	cout << "\033[2J\033[1;1H";
	mainMenu();
	sleepMilli(99);
}

void mainMenu(){
	using std::cout;
	using std::endl;

	cout << " _________ " << endl;
	cout << "|MAIN MENU|" << endl;
	cout << "|_________|" << endl;
	cout << endl << endl;
	cout << " _________ " << endl;
	cout << "|NEW GAME?|" << endl;
	cout << "|_________|" << endl;
	cout << " _____ " << " _____ " << endl;
	cout << "| YES |" << "|  NO |" << endl;
	cout << "|_____|" << "|_____|" << endl;
}

void credits(){
	using std::cout;
	using std::endl;

	cout << "___  ___  ___  ______  _____  ______ __   __         " << endl;
	cout << "|  \\/  | / _ \\ |  _  \\|  ___| | ___ \\\\ \\ / /         " << endl;
	cout << "| .  . |/ /_\\ \\| | | || |__   | |_/ / \\ V /   ______ " << endl;
	cout << "| |\\/| ||  _  || | | ||  __|  | ___ \\  \\ /   |______|" << endl;
	cout << "| |  | || | | || |/ / | |___  | |_/ /  | |           " << endl;
	cout << "\\_|__|_/\\_| |_/|___/  \\____/  \\____/ _ \\_/   ___     " << endl;
	cout << "  |_  || |  | | / _ \\ | ___ \\|_   _|| |     / _ \\    " << endl;
	cout << "    | || |  | |/ /_\\ \\| |_/ /  | |  | |    / /_\\ \\   " << endl;
	cout << "    | || |/\\| ||  _  ||    /   | |  | |    |  _  |   " << endl;
	cout << "/\\__/ /\\  /\\  /| | | || |\\ \\  _| |_ | |____| | | |   " << endl;
	cout << "\\____/  \\/  \\/ \\_| |_/\\_| \\_| \\___/ \\_____/\\_| |_/   " << endl;
	cout << " ( _ )                                               " << endl;
	cout << " / _ \\/\\                                             " << endl;
	cout << "| (_>  <                                             " << endl;
	cout << " \\___/\\/ _____  ______  ___  ______ ______           " << endl;
	cout << "| |  | ||_   _||___  / / _ \\ | ___ \\|  _  \\          " << endl;
	cout << "| |  | |  | |     / / / /_\\ \\| |_/ /| | | |          " << endl;
	cout << "| |/\\| |  | |    / /  |  _  ||    / | | | |          " << endl;
	cout << "\\  /\\  / _| |_ ./ /___| | | || |\\ \\ | |/ /           " << endl;
	cout << " \\/  \\/  \\___/ \\_____/\\_| |_/\\_| \\_||___/            " << endl;
}