// iv) Write a function Boolean isValidURL(String url).
// Input : str = “https://www.bigohtech.com/”
// Output : Yes
// Explanation :
// The above URL is a valid URL.
// Input : str = “https:// www.bigohtech.com/”
// Output : No
// Explanation :
// Note that there is a space after https://, hence the URL is invalid.
#include <bits/stdc++.h>
using namespace std;
bool isValidURL(string &url)
{
    bool contain_comma = false;
    for (auto itr : url) // Checking if url contains comma(,) in https://,
    {
        if (itr == ',')
        {
            contain_comma = true; // Updating the Flag
            break;
        }
    }
    if (contain_comma)
        return false;

    if (url.substr(0, 7) == "http://" || url.substr(0, 8) == "https://")
    {
        if (url.size() > 7 || url.size() > 8)
        {
            for (int ind = url.substr(0, 7) == "http://" ? 7 : 8; ind < url.size(); ind++)
            {
                if (url[ind] == ' ' && url[ind + 1] >= 'a' && url[ind + 1] <= 'z') // Checking if there is space after https://
                {
                    return false;
                }
                // if (url[ind] >= 'a' && url[ind] <= 'z')
                // {
                //     continue;
                // }
                if (isalnum(url[ind]) || url[ind] == '.' || url[ind] == '-' || url[ind] == '/' || url[ind] == '?' || url[ind] == '=' || url[ind] == '&' || url[ind] == '%')
                {
                    continue; // Skiping the case if the url have alphabet , number
                }
                else
                {
                    return false;
                }
            }

            string last_chars = url.substr(url.size() - 4);
            if (last_chars == ".com") // Checking for Domain Extentions
            {
                return true;
            }
            else
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

int main()
{
    string url;
    cout << "Enter Url : ";
    cin >> url;
    bool ans = isValidURL(url);
    // cout << (ans ? "true" : "false");
    if (ans == true)
    {
        cout << "Valid URL" << endl;
    }
    else
    {
        cout << "Invalid URL" << endl;
    }
    return 0;
}
