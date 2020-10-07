#include <iostream>
#include <regex>

#define PATTERN_1 "^(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}$"        /* BECH32 (P2WPKH) */
#define PATTERN_2 "^(tb1|[2nm]|bcrt)[a-zA-HJ-NP-Z0-9]{25,40}$"  /* BASE58 (P2PKH) */

bool validWallet(std::string wallet) {
    if(std::regex_match(wallet, std::regex(PATTERN_1))) {
        return true;
    } else if(std::regex_match(wallet, std::regex(PATTERN_2))) {
        return true;
    } else {
        return false;
    }
}

int main(void) {

    std::string w;
    std::cout << "Entre com a wallet: ";
    std::cin >> w;

    if(validWallet(w)) {
        std::cout << "Carteira valida!\n";
    } else {
        std::cout << "Carteira invalida!\n";
    }

    return 0;
}
