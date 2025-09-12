#include <iostream>
#include <windows.h>
using namespace std;
//Sleep helper
void wait(int ms) {
	Sleep(ms);
}
int main() {
cout<<"============================================\n";
cout<<" Welcome to SoftCare Baby Products\n";
cout<<"============================================\n";
wait(1000);
cout<<"\nLoading our special products";
for(int i = 0; i<3; i++) {
cout<<".";
cout.flush();
wait(500);
}
cout<<"\n\n Baby Soft Moisturizing Lotion\n";
cout<<" - Keeps your baby's skin soft and hydrated.\n";
cout<<" - Hypoallergenic and dermatologically tested.\n";
cout<<" - Mild fragrance for all day freshness.\n";
wait(2000);
cout<<"\n Gentle Baby Shampoo\n";
cout<<" - Tear-free formula.\n";
cout<<" - Enriched with natural extracts.\n";
cout<<" - Perfect for daily use.\n";
wait(2000);
cout<<"\n Special Offer: Buy2 Get 1 Free!\n";
wait(1500);
cout<<"\nThank you for choosing SoftCare Baby Products.\n";
cout<<"Visit our website or nearest store to order now.\n";
cout<<"\n============================================\n";
cout<<" Your baby's comfort, our care.\n";
cout<<"============================================\n";
return 0;
}