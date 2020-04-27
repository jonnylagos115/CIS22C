#include <iostream>
#include <iomanip>
#include "Currency.hpp"
using namespace std;


int main()
{
	Currency *pCurr, *pDollar = new Dollar("Dollar", "cent"), *pPound = new Pound("Pound", "pence"), 
	*pYen = new Yen("Yen", "sen"), *pRupee = new Rupee("Rupee", "paise"), 
	*pReal = new Real("Real", "centavo");
	string buffer, curr_name;

	do
	{
		cout << "Hello user, which operation would you like to do?\n";
		cout << "Options: 'add' 'subtract' 'list' 'end'";
		cin >> buffer;
		cout << "\n";

		if (buffer == "add")
		{
			cin >> pCurr;
			if (pCurr->getNoteName() == "Dollar")
				*pDollar + *pCurr;
			else if (pCurr->getNoteName() == "Pound")
				*pPound + *pCurr;
			else if (pCurr->getNoteName() == "Yen")
				*pYen + *pCurr;
			else if (pCurr->getNoteName() == "Rupee")
				*pRupee + *pCurr;
			else if (pCurr->getNoteName() == "Real")
				*pReal + *pCurr;
			delete pCurr;
			pCurr = nullptr;
		}
		else if (buffer == "sub")
		{
			cin >> pCurr;
			if (pCurr->getNoteName() == "Dollar")
				*pDollar - *pCurr;
			else if (pCurr->getNoteName() == "Pound")
				*pPound - *pCurr;
			else if (pCurr->getNoteName() == "Yen")
				*pYen - *pCurr;
			else if (pCurr->getNoteName() == "Rupee")
				*pRupee - *pCurr;
			else if (pCurr->getNoteName() == "Real")
				*pReal - *pCurr;
			delete pCurr;
			pCurr = nullptr;	
		}
		else if (buffer == "list")
		{
			cout << pDollar << pPound << pYen << pRupee << pReal;
		}
	} while (buffer != "end");
    return 0;
}