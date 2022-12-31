
#include <windows.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string generateKey(string msg, string key);
string encrypt(string msg, string key);
string decrypt(string cipher_text, string key);
int main()
{
    cout << "                                                   ------------------                             ";
    cout << " \n                                                    VIGNERE  CIPHER                                      ";

    cout << "  \n                                                   ------------------                            ";
    int choice;
    int flag = 1;
    string key;
    int length;
    system("color 3");
    string msg;
    cout << " \n\n\n Enter the Message:                ";
    getline(cin, msg);
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);

    for (int i = 0; msg[i] != '\0' && flag == 1;i++)
    {
        if ((msg[i] >= 'a' && msg[i] <= 'z') || (msg[i] >= 'A' && msg[i] <= 'Z') || (msg[i]==' ')) {
            flag = 1;
        }

        else
        {
            flag = 0;
        }
    }
    if (flag == 0) {
        cout << " Invalid input";

    }
    else {
        cout << "Enter key: ";
        cin >> key;
        key = generateKey(msg, key);
        transform(key.begin(), key.end(), key.begin(), ::toupper);
        cout << "\nEnter your choice:";
        cout << "\n 1 : Encryption.";
        cout << " \n 2 : Decryption.";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The Encrypted Message is =" << encrypt(msg, key) << endl;
            break;
        case 2:

            cout << "The Decrypted Message is =" << decrypt(msg, key) << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
        }

        return 0;

    }
}
    string generateKey(string msg, string key)
    {
        int x = msg.size();
        if (msg.size() < key.size())
            cout << " Invalid Key";
        for (int i = 0; ; i++)
        {
            if (x == i)
                i = 0;
            if (key.size() == msg.size())
                break;
            key.push_back(key[i]);

        }
        return key;
    }
    string encrypt(string msg, string key)
    {
        string cipher_text;

        for (int i = 0; i < msg.size(); i++)
        {
            char x = (msg[i] + key[i]) % 26;
            x += 'A';

            cipher_text.push_back(x);

        }
        return cipher_text;
    }
    string decrypt(string encrypted_msg, string key)
    {
        string orig_text;
        for (int i = 0; i < encrypted_msg.size(); i++)
        {
            char x = (encrypted_msg[i] - key[i] + 26) % 26;
            x += 'A';
            orig_text.push_back(x);
        }
        return orig_text;
    }
