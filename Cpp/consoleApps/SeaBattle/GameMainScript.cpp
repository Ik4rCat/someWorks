#include <iostream>
#include <string>

#include <scripts/SeaBattle.h>

using namespace std;

void ascii(){

    cout << "\033[0m";
    cout << "\033[1;37m"; 

    cout << endl;
    cout << "                          ...----...." << "\n";
    cout << "                    ..-:\"''         ''\"-.." << "\n";
    cout << "                 .-'                      '-." << "\n";
    cout << "               .'              .     .       '." << "\n";
    cout << "             .'   .          .    .      .    .''." << "\n";
    cout << "           .'  .    .       .   .   .     .   . ..:." << "\n";
    cout << "         .' .   . .  .       .   .   ..  .   . ....::." << "\n";
    cout << "        ..   .   .      .  .    .     .  ..  . ....:IA." << "\n";
    cout << "       .:  .   .    .    .  .  .    .. .  .. .. ....:IA." << "\n";
    cout << "      .: .   .   ..   .    .     . . .. . ... ....:.:VHA." << "\n";
    cout << "      '..  .  .. .   .       .  . .. . .. . .....:.::IHHB." << "\n";
    cout << "     .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM." << "\n";
    cout << "    .:.... .   . .'::\"'.. .'   .'  ...:.:.:II;,. .. ..:IHIMMA" << "\n";
    cout << "    ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM" << "\n";
    cout << "   .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM" << "\n";
    cout << "  .:.:V.:IVHHHHHHHMHMHHH::..:\" .:HIHHHHHHHHHHHHHMHHA. .VMMM." << "\n";
    cout << "  :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI" << "\n";
    cout << "  ::V..:VIHHHHHHMMMHHHH HH. .   .I\":IIM HHMM HH HH HH HAPI:WMM" << "\n";
    cout << "  ::\" . .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:'':H:WM" << "\n";
    cout << "  :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW" << "\n";
    cout << "  '.  ..:..:.:IHHHHHMMHV\" .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV" << "\n";
    cout << "   :.  .:...:\".:.:TPP\"   .AVMMHMMA.:. \"VMMHHHP.:... .. :IVAI" << "\n";
    cout << "  .:.   '... .:\"'   .   ..HMMMHMMMA::. .\"VHHI:::....  .:IHW'" << "\n";
    cout << "  ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM" << "\n";
    cout << ": .   .'\"' .:.V\". .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM." << "\n";
    cout << ":.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV\":T::I::.\".:IHIMA" << "\n";
    cout << "'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH" << "\n";
    cout << "  \"IHH:.II:.. .:. .  . . . \" :HB\"\" . . ..PI:.::.:::..:IHHMMV\"" << "\n";
    cout << "   :IP\"\"HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM\"" << "\n";
    cout << "   :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM" << "\n";
    cout << "   :\"VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI" << "\n";
    cout << "   :.\"VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI" << "\n";
    cout << "   :..VIHIHMMMI...::.,:.,:!\"I:!\"I!\"I!\"V:AI:VAMMMMMMHMMMMMM'" << "\n";
    cout << "   ':.HIHIMHHA:\"!!\"I.:AXXXVVXXXXXXXA:.\"HPHIMMMMHHMHMMMMMV" << "\n";
    cout << "     V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM" << "\n";
    cout << "       'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'\"'" << "\n";
    cout << "        I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI" << "\n";
    cout << "       .I::. \"H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'" << "\n";
    cout << "       :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM" << "\n";
    cout << endl;

    cout << "\033[0m";
    cout << "\033[1;33m";

}


int main()
{
    while (true)
    {
        int usrChoice;

        //ascii art
        ascii();

        cout << "Welcome to Sea Battle CLI!" << endl;
        cout << "This is a simple command-line interface for playing Sea Battle." << endl;
        cout << "Enjoy the game!" << endl;

        cout << endl;

        cout << "==========================" << endl;
        cout << "games versions: " <<endl;
        cout << "==========================" << endl;
        cout << "classic game: " << endl;
        cout << "1. classic game with bot " << endl;
        cout << "2. classic game with another player " << endl;

        cout << endl;

        cout << "advanced game: " << endl;
        cout << "3. advanced game with bot " << endl;
        cout << "4. advanced game with another player " << endl;

        cout << endl;

        cout << "steam gaming: " << endl;
        cout << "5. steam classic game with another player " << endl;   
        
        cout << endl;

        cout << "0. exit: " << endl;

        cout << endl;

        cout << "choice game mod: ";
        cin >> usrChoice;

        switch (usrChoice)
        {
        case 1:
            cout << "Starting classic game with bot..." << endl;
            // classic game with bot
            break;
        case 2:
            cout << "Starting classic game with another player..." << endl;
            // classic game with another player
            break;
        case 3:
            cout << "Starting advanced game with bot..." << endl;
            // advanced game with bot
            break;
        case 4:
            cout << "Starting advanced game with another player..." << endl;
            // advanced game with another player
            break;
        case 5:
            cout << "Starting steam classic game with another player..." << endl;
            // steam classic game with another player
            break;
        case 0:
            return 0;

        default: cout << "Invalid choice. Please try again." << endl; break;
        }
    }
    
    return 0;


}