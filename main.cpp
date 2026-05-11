

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
// int main() {
//     // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
//     auto lang = "C++";
//     std::cout << "Hello and welcome to " << lang << "!\n";
//
//     for (int i = 1; i <= 5; i++) {
//         // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
//         std::cout << "i = " << i << std::endl;
//     }
//
//     return 0;
//     // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
// }

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function declarations
long long pthFactor(long long n, long long p);
vector<string> topArticles(int limit);

int main() {

    int choice;

    cout << "===== Annex Assessment Menu =====" << endl;
    cout << "1. Find p-th Factor" << endl;
    cout << "2. Get Top Articles" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    // Question 1
    if (choice == 1) {

        long long n, p;

        cout << "\nEnter the number (n): ";
        cin >> n;

        cout << "Enter factor position (p): ";
        cin >> p;

        long long result = pthFactor(n, p);

        if (result == 0) {
            cout << "\nThe number has fewer than "
                 << p << " factors." << endl;
        }
        else {
            cout << "\nThe " << p
                 << "-th factor is: "
                 << result << endl;
        }
    }

    // Question 3
    else if (choice == 2) {

        int limit;

        cout << "\nEnter number of top articles: ";
        cin >> limit;

        vector<string> articles = topArticles(limit);

        cout << "\nTop Articles:" << endl;

        for (int i = 0; i < (int)articles.size(); i++) {
            cout << i + 1 << ". "
                 << articles[i] << endl;
        }
    }

    // Invalid choice
    else {
        cout << "\nInvalid option selected." << endl;
    }

    return 0;
}
