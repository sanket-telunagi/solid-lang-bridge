#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
    
    int l, b , h ;
    
   public :
   
   Box (int  a, int x,int  c) {
        l = a ; b = x ; h = c ;     
   }
   
   Box() {
       l = 0 ; b = 0 ; h= 0 ;
   }
    
    friend ostream & operator << (ostream &out, const Box &c);
    bool operator < (Box x) {
        if ((l < x.l) | ((b < x.b) && (l == x.l)) | ((h < x.h) && (l == x.l) && (b == x.b))){
            return true ;
        }return false;
    }
    
    long long CalculateVolume(){
        return l*1LL*b* 1LL *h ;
    }
} ;

ostream & operator << (ostream &out, const Box &c)
{
    out << c.l << " " << c.b << " " << c.h ;
    
    return out;
}



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}