/*****Version 1.1***********/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char* file_name = "input.txt";
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
	readFile(baseHP1,baseHP2,wp1,wp2,ground);

	//write your code here
    int paladinHP1 = 1;
	int paladinHP2 = 1;

	if ( 999 == baseHP1 )
    {
        fOut = 1;
        goto exit;
    }

    if ( 888 == baseHP2 )
    {
        fOut = 0.00;
        goto exit;
    }

	for ( int i = 2; i < sqrt(baseHP1); ++i )
    {
        if ( 0 == ( baseHP1 % i ) )
        {
            paladinHP1 = 0;
            break;
        }
    }

    for ( int i = 2; i < sqrt(baseHP2); ++i )
    {
        if ( 0 == ( baseHP2 % i ) )
        {
            paladinHP2 = 0;
            break;
        }
    }

    if ( 1 == paladinHP1 )
    {
        fOut = 0.99;
        goto exit;
    }
    else if ( 1 == paladinHP2 )
    {
        fOut = 0.01;
        goto exit;
    }
    else if ( ( 1 == paladinHP1 ) && ( 1 == paladinHP2) )
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

    int realHP1, realHP2;
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
            break;
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
            break;
    }

    if ( ground == baseHP1 )
    {
        realHP1 += realHP1 * 0.1;
        if ( 999 < realHP1 )
            realHP1 = 999;
    }

    if ( ground == baseHP2 )
    {
        realHP2 += realHP2 * 0.1;
        if ( 999 < realHP2 )
            realHP2 = 999;
    }

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
            break;
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
            break;
    }

    fOut = ( realHP1 - realHP2 + 999.0 ) / 2000.0;

	display(fOut);
    return 0;

    exit:
        display(fOut);
        return 0;
}
