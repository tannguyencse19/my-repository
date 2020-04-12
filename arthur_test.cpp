/*****Version 1.1***********/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
/*int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char* file_name = "E:/DAI_CUONG/KTLT/Assignment_0/Assignment_0/input.txt";
	ifstream in;
	in.open(file_name);
	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;
	in.close();
	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;
	in.close();
	return 1;

}
*/
void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}


int main(void)
{
	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	//readFile(baseHP1,baseHP2,wp1,wp2,ground);

	//Testcase
	cout << "baseHP1 = "; cin >> baseHP1;
	cout << "wp1 = "; cin >> wp1;
	cout << "baseHP2 = "; cin >> baseHP2;
	cout << "wp2 = "; cin >> wp2;
	cout << "ground = "; cin >> ground;

	//Write your code here
	int realHP1, realHP2;

	if ( 999 == baseHP1 ) //Ngay tu dau chu khong phai sau tinh toan
    {
        fOut = 1;
        goto exit;
    }

    if ( 888 == baseHP2 )
    {
        cout << "Chay vao day" << endl;
        fOut = 0.00;

        goto exit;
    }

    int paladinHP1 = 1;
	for ( int i = 2; i < sqrt(baseHP1); ++i )
    {
        if ( 0 == ( baseHP1 % i ) )
        {
            paladinHP1 = 0;
            break;
        }
    }

    int paladinHP2 = 1;
    for ( int i = 2; i < sqrt(baseHP2); ++i )
    {
        if ( 0 == ( baseHP2 % i ) )
        {
            paladinHP2 = 0;
            break;
        }
    }

    if ( ( 1 == paladinHP1 ) && ( 1 == paladinHP2) ) //Worst case : Both are paladin
    {
        if ( baseHP1 > baseHP2 )
        {
            fOut = 0.99;
            goto exit;
        }
        else if ( baseHP1 == baseHP2 )
        {
            fOut = 0.50;
            goto exit;
        }
        else
        {
            fOut = 0.01;
            goto exit;
        }
    }
    else if ( 1 == paladinHP1 )
    {
        fOut = 0.99;
        goto exit;
    }
    else if ( 1 == paladinHP2 )
    {
        fOut = 0.01;
        goto exit;
    }

    switch( wp1 )
    {
        case 1:
        case 2:
        case 3:
            realHP1 = baseHP1;
            break;
        case 0:
            realHP1 = baseHP1 / 10;
            break;
        default:
            cout << "wp1 case1-0 invalid !" << endl;
    }

    switch( wp2 )
    {
        case 1:
        case 2:
        case 3:
            realHP2 = baseHP2;
            break;
        case 0:
            realHP2 = baseHP2 / 10;
            break;
        default:
            cout << "wp2 case1-0 invalid !" << endl;
    }

    if ( ground == baseHP1 )
    {
        realHP1 += realHP1 * 0.1;
        if ( 999 < realHP1 )
            realHP1 = 999;
        cout << "Da chay vao ground!" << endl;
    }

    if ( ground == baseHP2 )
    {
        realHP2 += realHP2 * 0.1;
        if ( 999 < realHP2 )
            realHP2 = 999;
        cout << "Da chay vao ground!" << endl;
    }
cout << "realHP1 = " << realHP1 << ' ' << "realHP2 = " << realHP2 << endl;
    switch( wp1 )
    {
        case 2:
            if ( realHP1 < realHP2 )
            {
                fOut = 0.50;
                goto exit;
            }
            break;
        case 3:
            realHP1 *= 2;
            if ( 999 < realHP1 )
                realHP1 = 999;
            break;
        default:
            cout << "wp1 2-3 invalid !" << endl;
    }

    switch( wp2 )
    {
        case 2:
            if ( 3 == wp1 );
            else if ( realHP2 < realHP1 ) //Notes : Check later
            {
                fOut = 0.50;
                goto exit;
            }
            break;
        default:
            cout << "wp2 2-3 invalid !" << endl;
    }

    //All equipment are ready
    cout << "Khong phai truong hop dac biet" << endl;
    cout << "realHP1 = " << realHP1 << ' ' << "realHP2 = " << realHP2 << endl;
    fOut = ( realHP1 - realHP2 + 999.0 ) / 2000.0;

	display(fOut);
    return 0;

    exit:
        cout << "Truong hop dac biet " << endl;
        display(fOut);
        return 0;

	return 0;
}
