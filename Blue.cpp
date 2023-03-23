#include <pigpio.h>
#include <iostream>

using namespace std;

void sendByte(unsigned int x)
{
    serWriteByte(x,6);serWriteByte(x,77);
    gpioSleep(PI_TIME_RELATIVE, 1, 500000); // sleep for 1.5
}

void readByte(unsigned x)
{
    if(serDataAvailable(x)>0)
        cout << serReadByte(x) << endl;
    gpioSleep(PI_TIME_RELATIVE, 0, 500000);
    /*
     * add delay is ok. Because read also need time.
     */
}

int main(void)
{
    if (gpioInitialise() < 0) 
    {
        cout << "Failed" << endl;
    } 
    else 
    {
        cout << "PIGPIO is ready" << endl;
    }
    
    unsigned int x = serOpen("/dev/ttyS0", 9600, 0) ;
    cout << x <<endl;
    
    if (x < 0)
    {
        cout << "Fail to open Serial port." << endl;
    }
    else
    {
        cout << "Success to Open" << endl;
    }
    char buff[8];
    while (1)
    {
        /*
        if(serDataAvailable(x))
        {
            serRead(x,buff,8);
            cout<<buff[0];
            gpioSleep(PI_TIME_RELATIVE, 0, 500000);
        }
        cout<<serDataAvailable(x)<< endl;
        */
        if(serDataAvailable(x))
        {
            while(serDataAvailable(x))
            {
                cout << serReadByte(x) << endl;
            }
            
        }
    }
    
    
    return 0;
}
