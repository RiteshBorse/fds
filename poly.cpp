#include<iostream>
using namespace std;


typedef struct{
     int coefficient;
     int exponent;
}polynomials;


class polynomial{
   private:
     
   	 int totalTerms;
     polynomials poly[10];

   public:
      void readPoly();
	  void display(); 
	 polynomial addition(polynomial B);
  
};

void polynomial :: readPoly(){
  
     cout<<"Enter total terms in the polynomial : ";
     cin>>totalTerms;
     
          for(int i=0 ; i<totalTerms ; i++){

				 cout<<" Enter Exponent :";
                 cin>>poly[i].exponent;

                 cout<<" Enter coefficient :";
                 cin>>poly[i].coefficient;
           }
}


void polynomial :: display(){
	int i;
	cout<<"Your polynomial is : ";
  	 for( i=0 ; i<totalTerms ; i++){
     	
        cout<<poly[i].coefficient<<"X^"<<poly[i].exponent ;
		if(i< totalTerms-1){
			cout<<" + ";		
		}
	}
  cout<<endl;
}

polynomial polynomial :: addition(polynomial B){
    int i,j,k;
  
	 i=j=k=0;
	
	polynomial C;
		while(i<totalTerms && j<B.totalTerms){
			if(poly[i].exponent==B.poly[j].exponent)
			{
			C.poly[k].coefficient = poly[i].coefficient + B.poly[j].coefficient;
			C.poly[k].exponent = poly[i].exponent;
			i++ ; j++ ; k++ ;
			}else if(poly[i].exponent>B.poly[j].exponent)
			{
				C.poly[k].coefficient = poly[i].coefficient ;
			    C.poly[k].exponent = poly[i].exponent;
		     	i++ ; k++ ;
			}else{
				C.poly[k].coefficient = B.poly[j].coefficient;
		 		C.poly[k].exponent = B.poly[j].exponent;
				 j++ ; k++ ;
			}
		
		}

 	 while(i<totalTerms){
			C.poly[k].coefficient = poly[i].coefficient ;
		    C.poly[k].exponent = poly[i].exponent;
	     	i++ ; k++ ;
	}

	 while(j<B.totalTerms){
			C.poly[k].coefficient = B.poly[j].coefficient;
		   	C.poly[k].exponent = B.poly[j].exponent;
       		 j++ ; k++ ;
	}

     C.totalTerms = k-1 ;
     return C;
}

int main(){
	polynomial  p,p1  ;

	p.readPoly();
	p.display();
    p1.readPoly();
	p1.display();
    p.addition(p1);



	return 0;
}