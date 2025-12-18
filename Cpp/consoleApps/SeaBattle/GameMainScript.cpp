#include <iostream>
#include <string>

using namespace std;

void ascii(){

    cout << "\033[0m";
    cout << "\033[1;37m"; 

    cout << endl;
    cout << "                          ...----...." << endl;
    cout << "                    ..-:\"''         ''\"-.." << endl;
    cout << "                 .-'                      '-." << endl;
    cout << "               .'              .     .       '." << endl;
    cout << "             .'   .          .    .      .    .''." << endl;
    cout << "           .'  .    .       .   .   .     .   . ..:." << endl;
    cout << "         .' .   . .  .       .   .   ..  .   . ....::." << endl;
    cout << "        ..   .   .      .  .    .     .  ..  . ....:IA." << endl;
    cout << "       .:  .   .    .    .  .  .    .. .  .. .. ....:IA." << endl;
    cout << "      .: .   .   ..   .    .     . . .. . ... ....:.:VHA." << endl;
    cout << "      '..  .  .. .   .       .  . .. . .. . .....:.::IHHB." << endl;
    cout << "     .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM." << endl;
    cout << "    .:.... .   . .\"::\"'.. .   .  . .:.:.:II;,. .. ..:IHIMMA" << endl;
    cout << "    ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM" << endl;
    cout << "   .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM" << endl;
    cout << "  .:.:V.:IVHHHHHHHMHMHHH::..:\" .:HIHHHHHHHHHHHHHMHHA. .VMMM." << endl;
    cout << "  :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI" << endl;
    cout << "  ::V..:VIHHHHHHMMMHHHHHH. .   .I\":IIMHHMMHHHHHHHHHHHAPI:WMM" << endl;
    cout << "  ::\" . .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:'':H:WM" << endl;
    cout << "  :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW" << endl;
    cout << "  '.  ..:..:.:IHHHHHMMHV\" .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV" << endl;
    cout << "   :.  .:...:\".:.:TPP\"   .AVMMHMMA.:. \"VMMHHHP.:... .. :IVAI" << endl;
    cout << "  .:.   '... .:\"'   .   ..HMMMHMMMA::. .\"VHHI:::....  .:IHW'" << endl;
    cout << "  ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM" << endl;
    cout << ": .   .'\"' .:.V\". .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM." << endl;
    cout << ":.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV\":T::I::.\".:IHIMA" << endl;
    cout << "'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH" << endl;
    cout << "  \"IHH:.II:.. .:. .  . . . \" :HB\"\" . . ..PI:.::.:::..:IHHMMV\"" << endl;
    cout << "   :IP\"\"HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM\"" << endl;
    cout << "   :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM" << endl;
    cout << "   :\"VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI" << endl;
    cout << "   :.\"VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI" << endl;
    cout << "   :..VIHIHMMMI...::.,:.,:!\"I:!\"I!\"I!\"V:AI:VAMMMMMMHMMMMMM'" << endl;
    cout << "   ':.HIHIMHHA:\"!!\"I.:AXXXVVXXXXXXXA:.\"HPHIMMMMHHMHMMMMMV" << endl;
    cout << "     V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM" << endl;
    cout << "       'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'\"'" << endl;
    cout << "        I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI" << endl;
    cout << "       .I::. \"H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'" << endl;
    cout << "       :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM" << endl;
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