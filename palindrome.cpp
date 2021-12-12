#include <iostream>
#include <string>
#include <vector>

// CheckForPalindrome will evaluate if the substring within "s" as identified by midpoint "mid"
// is a palindrome of length "target"
// If it confirms that, it will seek to see if the palindrome is actually bigger than target
// by extending the start/end indexes of the substring its seaching for
size_t CheckForPalindrome(const std::string& s, size_t mid, size_t target)
{
    size_t result = 0;
    size_t start, end;
    size_t targethalf = target / 2;
    size_t leftadjust = !(target % 2); // 1 for even length strings, 0 for odd

    end = targethalf + mid;
    if (end >= s.size())
    {
        return 0;
    }

    if ((mid + leftadjust) < targethalf)
    {
        return 0;
    }

    start = (mid + leftadjust - targethalf);

    // check if this is a basic palindrome between start and end
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return 0;
        }
        start++;
        end--;
    }

    result = target;

    // at this point we know its a palindrome of length target - but is it bigger than that?
    // we can stetch out to see
    start = (mid + leftadjust - targethalf);
    end = targethalf + mid;
    while (start > 0 && (end+1) < s.size())
    {
        start--;
        end++;
        if (s[start] == s[end])
        {
            result += 2;
        }
        else
        {
            break;
        }
    }
    return result;
}


// returns the longest palindrome within a string
std::string FingLongestPalindrome(const std::string& s)
{
    if (s.size() == 0)
    {
        return "";
    }

    std::string result = s.substr(0, 1);

    if (s.size() == 1)
    {
        return result;
    }

    // s is already validated to be at least a length of 2
    size_t bestlength = 1;
    size_t bestmidpoint = 0;
    size_t target = 2;

    // Look for even sized palindromes
    for (size_t mid = 0; mid < s.size()-1; mid++)
    {
        if (s[mid] == s[mid + 1])
        {
            size_t tmp = CheckForPalindrome(s, mid, target);
            if (tmp > bestlength)
            {
                bestlength = tmp;
                target = bestlength + 2;
                bestmidpoint = mid;
            }
        }
    }

    // readjust target to be the next odd length up from
    // the best length palindrome found so far. It's possible no even length palindromes were found
    target = (bestlength == 1) ? 3 : (bestlength + 1);

    // Look for odd sized palindromes
    for (size_t mid = 1; mid < s.size() - 1; mid++)
    {
        if (s[mid - 1] == s[mid + 1])
        {
            size_t tmp = CheckForPalindrome(s, mid, target);
            if (tmp > bestlength)
            {
                bestlength = tmp;
                target = bestlength + 2;
                bestmidpoint = mid;
            }
        }
    }


    size_t leftadjust = !(bestlength % 2); // 1 for even length strings, 0 for odd
    result = s.substr(bestmidpoint + leftadjust - bestlength / 2, bestlength);
    return result;

}

int main()
{
    const std::string s0 = "Tenderloin chuck kielbasa tongue ham flank, strip steak alcatra sirloin pork prosciutto tri-tip. Cow hamburger tail, biltong meatball pancetta leberkas. Kielbasa cow ham hock doner drumstick. Ham ground round short ribs meatball pastrami tenderloin burgdoggen pig ham hock beef ribs bresaola cupim prosciutto fatback kevin. Buffalo fatback pork loin bacon kielbasa, ham filet mignon porchetta leberkas ham hock salami ball tip tail. Porchetta picanha chislic leberkas ground round kielbasa salami pancetta burgdoggen shank sirloin ham boudin shankle pork chop. Buffalo corned beef meatball strip steak shoulder jerky flank tongue drumstick leberkas tenderloin pastrami sausage pork loin doner. Frankfurter leberkas meatloaf, cow turkey kevin andouille tail ball tip shankle ham hock short ribs chicken hamburger ribeye.Burgdoggen ground round porchetta, cow shankle alcatra buffalo.T - bone frankfurter capicola meatball.Meatball kielbasa andouille rump alcatra.Shoulder bacon capicola, picanha meatloaf landjaeger jerky chislic cupim sausage alcatra kielbasa.Pork belly chuck jerky chicken burgdoggen.Landjaeger meatball cupim shank ball tip, porchetta drumstick kevin.Leberkas pastrami rump shoulder burgdoggen, pig flank jowl boudin filet mignon.Corned beef bacon pancetta jowl, ribeye tail pork loin short loin tenderloin shankle jerky flank.Drumstick landjaeger ham hock, turducken corned beef meatball pastrami shank meatloaf.Chicken biltong jerky porchetta venison cupim, jowl strip steak.Swine pork pig ball tip turkey beef ribs sirloin ground round.Turkey porchetta sirloin kielbasa, doner bresaola strip steak picanha meatball beef ribs pancetta.Ball tip meatball chuck capicola, filet mignon leberkas alcatra frankfurter short loin.Ribeye jerky shankle burgdoggen meatball.Beef capicola pork chop short ribs pork loin chislic shankle pork spare ribs pig.Filet mignon sausage spare ribs,TOPSPOTTOPSPOTtenderloin ball tip ham kielbasa brisket pork loin.Short loin buffalo spare ribs leberkas t - bone chislic pork prosciutto.Ham hock chuck picanha, pastrami strip steak venison swine boudin. Short loin kielbasa spare ribs, pastrami meatloaf boudin brisket bacon fatback rump shoulder capicola. Pork ham shoulder, ground round jowl tongue tri-tip kielbasa ribeye shankle landjaeger. Pig buffalo short loin jowl kevin meatball tri-tip. Burgdoggen cupim tail, ham hock chislic beef drumstick turducken bacon tri-tip jerky corned beef.Tri-tip pancetta drumstick cupim pork loin chislic pork chop strip steak buffalo rump andouille. Prosciutto alcatra doner, landjaeger spare ribs picanha buffalo ribeye short loin turducken. Capicola prosciutto shankle salami. Corned beef meatloaf meatball bacon fatback short loin doner frankfurter. Picanha tenderloin beef, brisket bresaola flank pig. Landjaeger ground round pancetta shank, porchetta jerky ham hock jowl cow filet mignon pastrami boudin. Beef ham leberkas, turkey shoulder venison salami jowl porchetta tongue pastrami short loin strip steak chislic.";
    const std::string s1 = "ABA";
    const std::string s2 = "RACECAR";
    const std::string s3 = "RACEECAR";
    const std::string s4 = "AMANAPLANACANALPANAMA";
    const std::string s5 = "zzAMANAPLANACANALPANAMA....RACEECAR....RACECAR...ABA";
    const std::string s6 = "zzABA...RACECAR...RACEECAR..zzAMANAPLANACANALPANAMATOPSSPOT";
    const std::string s7 = "abcdefBB";
    const std::string s8 = "abcdefBBB";
    const std::string s9 = "9999999999999999999999999999999999999999999999999999999999999";

    const std::vector<std::string> testcases = { s0, s1, s2, s3, s4, s5, s6, s7, s8, s9 };

    for (const auto& s : testcases)
    {
        std::string result = FingLongestPalindrome(s);
        std::cout << result << std::endl;
    }


    return 0;

}
