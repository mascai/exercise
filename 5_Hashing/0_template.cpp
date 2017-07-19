#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void Print(const unordered_map<string, string>& u){
   for(const auto& n : u){
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
}

int main()
{
    // Create an unordered_map of three strings (that map to strings)
    unordered_map<string, string>u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
    // Iterate and print keys and values
    Print(u);
    
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
    cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";
    return 0;
}
