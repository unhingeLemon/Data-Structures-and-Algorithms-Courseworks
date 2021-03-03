#include <iostream>
#include <queue>
using namespace std;

struct crew
{
	int hc;
	int st;
	int et;
};

struct guest
{
	int h;
	int t;
};

int main()
{
	crew *Crew;
	guest Guest;
	queue <guest> GuestLine;
	int H, C, Q;
	cin >> H >> C >> Q;
	Crew = new crew[C];
	cout << endl << "Crew Information..." << endl;
	for (int i = 0; i < C; i++)
		cin >> Crew[i].hc >> Crew[i].st >> Crew[i].et;
	cout << endl << "Guest Information..." << endl << endl;
	for (int i = 0; i < Q; i++)
	{
		cin >> Guest.h >> Guest.t;
		GuestLine.push(Guest);
	}
	cout << "\nOutput...\n";
	while (!GuestLine.empty())
	{
    //write your codes here...
//     bool flag = false;
// 		guest g = GuestLine.front();
//     int range;
//     for(int i = 0; i < C; i++) {
//       if(Crew[i].st < g.t && Crew[i].et > g.t && Crew[i].hc < g.h){
//         flag = true
//       }
      
//     }
    
//     if(flag){
//       cout << "YES\n";
//     } else {
//       cout << "NO\n";
//     }
    
    
    for(int i = 0;i < Q;i++){
        guest g = GuestLine.front();
        for(int j = 0;j<C;j++) {
          if(g.t >= Crew[j].st && g.t <= Crew[j].et){
            if(g.h > Crew[j].hc){
              cout << "YES\n";
              break;
            } else {
              cout << "NO\n";
              break;
            }
          } else if((j+1)==C){
            if(g.t > Crew[j].et || g.t < Crew[j].st) {
              cout << "YES\n";
              break;
            }
            

          }
        }
      GuestLine.pop();
    }
    
    
	}
}
