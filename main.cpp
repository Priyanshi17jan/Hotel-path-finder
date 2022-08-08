/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src, unordered_map<int, string> &m)
{
    int dist[V];
    vector<pair<int, int>> ans;

    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        ans.push_back({dist[i], i});
    }
    sort(ans.begin(), ans.end());
    for (int i = 1; i < V; i++)
    {
        cout << m[ans[i].second] << "            " << ans[i].first << "km" << endl;
    }
}

void case1(int x, int y)
{

    int hx1 = 8, hy1 = 0;
    int hx7 = 11, hy7 = 8;

    int d01 = sqrt((hx1 - x)*(hx1 - x) + (hy1 - y)*(hy1 - y)); // dist of h1 and user
    int d07 = sqrt((hx7 - x)*(hx7 - x) + (hy7 - y)*(hy7 - y)); // dist of h7 and user

    int graph[V][V] = {{0, d01, 0, 0, 0, 0, 0, d07, 0},
                       {d01, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {d07, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    unordered_map<int, string> m;
    m.insert({1, "Hotel Jaypee Palace"});
    m.insert({2, "Hotel Prince Palace"});
    m.insert({3, "Crowne Plaza       "});
    m.insert({4, "Hotel Heera Palace "});
    m.insert({5, "Hotel Bliss        "});
    m.insert({6, "University Hotel   "});
    m.insert({7, "Sunset Lodge       "});
    m.insert({8, "Ramada Limited     "});

    dijkstra(graph, 0, m);
}

void hotel_list(int x)
{
    switch (x)
    {
    case 1:
    {
        cout << "Enter you current location corrdinates in terms of x and y " << endl;
        int x, y;
        cin >> x >> y;
        case1(x, y);
    }
    break;
    case 2:
    {
        cout << "Hotel Jay Palace" << endl;
        cout << "Hotel  Palace   " << endl;
        cout << "Hotel  Pride    " << endl;
        cout << "Lake Place Inn  " << endl;
        cout << "Beacon Motel    " << endl;
        cout << "Comfort B&B     " << endl;
        cout << "The Fresco Hotel" << endl;
        cout << "Motel On Main   " << endl;
        cout << "Holly House     " << endl;
        cout << "High Desert Inn " << endl;
    }
    break;
    case 3:
    {
        cout << "Hotel Jaypee Palace" << endl;
        cout << "Four Seasons" << endl;
        cout << "Budget Suites" << endl;
        cout << "American Inn" << endl;
        cout << "Relax Inn" << endl;
        cout << "Sapphires Hotel" << endl;
        cout << "The Glory Hote" << endl;
        cout << "Time Motel" << endl;
        cout << "The Breakers" << endl;
        cout << "Friendship Inn" << endl;
    }
    break;
    case 4:
    {
        cout << "The Venetian" << endl;
        cout << "Spotlight Hotel" << endl;
        cout << "The Mississippi Hotel" << endl;
        cout << "Green Tortoise Hostel" << endl;
        cout << "The Orchard Hotel" << endl;
        cout << "Spring Brook" << endl;
        cout << "Hotel Agoura" << endl;
        cout << "Wonder Hill Inn" << endl;
        cout << "The New Yorker" << endl;
        cout << "Beachwalk Resort" << endl;
    }
    break;

    case 5:
    {
        cout << "Etiquette Suitese" << endl;
        cout << "Water Vibe Resorts" << endl;
        cout << "Consulate Hotel" << endl;
        cout << "Quaint Motel" << endl;
        cout << "Cape Grace" << endl;
        cout << "Fountain Fun" << endl;
        cout << "The New View" << endl;
        cout << "White Season Resort" << endl;
        cout << "Hotel Occazia" << endl;
        cout << "Purple Orchid" << endl;
    }
    break;

    case 6:
    {
        cout << "Prestige proga Inn" << endl;
        cout << "The Glory Hotele" << endl;
        cout << "The Mutiny Hotel" << endl;
        cout << "The Manhattan" << endl;
        cout << "Parallel Shine" << endl;
        cout << "Eden Roc" << endl;
        cout << "Coastal bay hote" << endl;
        cout << "Dream Connect" << endl;
        cout << "Purple Villa" << endl;
        cout << "Amar villas" << endl;
    }
    break;

    default:

        return;
    }
}

class hotel
{

    string name;
    int price;
    int room_type;
};

// int mat[6][10]={
//{78,89,90,56,23,13,25,67,76,78}

// Function to display the menu
void menu()
{
    cout << "Press 1 if you want to go to location1\n";
    cout << "Press 2 if you want to go to location2\n";
    cout << "Press 3 if you want to go to location3\n";
    cout << "Press 4 if you want to go to location4\n";
    cout << "Press 5 if you want to go to location5\n";
    cout << "Press 6 if you want to go to location6\n";
    cout << "Press 7 to exit\n";
}

// Function to calculate and display the result
void result()
{

    // Display the result
    menu();
    int choice;
    cin >> choice;
    cout << "-----------------Nearest hotel near you -------------" << endl;
    hotel_list(choice);
}

int main()
{
    result();

    return 0;
}
