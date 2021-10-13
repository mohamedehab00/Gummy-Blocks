#include <bits/stdc++.h>
using namespace std;
const int N  = 10;
int grid[N][N];
const int Bricks_NO = 8;
int score = 0;
vector<pair<vector<vector<int>>,char>> Bricks(Bricks_NO);
void initialize()
{
    vector<vector<int>> brick;
    pair<vector<vector<int>>,char> brick_pair;
    score = 0;
    //initialize BRICK1
    brick = {{1,0,0},{1,0,0},{1,1,1}};
    brick_pair.first = brick;
    brick_pair.second = '1';
    Bricks[0]=brick_pair;
    //initialize BRICK2
    brick = {{1,1,0},{1,1,0},{0,0,0}};
    brick_pair.first = brick;
    brick_pair.second = '2';
    Bricks[1]=brick_pair;
    //initialize BRICK3
    brick = {{1,1,1},{1,1,1},{1,1,1}};
    brick_pair.first = brick;
    brick_pair.second = '3';
    Bricks[2]=brick_pair;
    //initialize BRICK4
    brick = {{1,1,1},{0,0,0},{0,0,0}};
    brick_pair.first = brick;
    brick_pair.second = '4';
    Bricks[3]=brick_pair;
    //initialize BRICK5
    brick = {{1,0,0},{0,0,0},{0,0,0}};
    brick_pair.first = brick;
    brick_pair.second = '5';
    Bricks[4]=brick_pair;
    //initialize BRICK6
    brick = {{1,1,0},{0,0,0},{0,0,0}};
    brick_pair.first = brick;
    brick_pair.second = '6';
    Bricks[5]=brick_pair;
    //initialize BRICK7
    brick = {{1,1,1},{0,0,1},{0,0,1}};
    brick_pair.first = brick;
    brick_pair.second = '7';
    Bricks[6]=brick_pair;
    //initialize BRICK8
    brick = {{1,1,0},{1,0,0},{0,0,0}};
    brick_pair.first = brick;
    brick_pair.second = '8';
    Bricks[7]=brick_pair;
    //Clean Main grid
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            grid[i][j]=0;
        }
    }
}
vector<int> generate()
{
    srand(time(NULL));
    vector<int> idx(3);
    idx[0] = rand() % Bricks_NO;
    idx[1] = rand() % Bricks_NO;
    idx[2] = rand() % Bricks_NO;
    return idx;
}
void print_grid(vector<int> v)
{
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++)
    {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
    cout<<endl;
    cout << "YOUR SCORE IS: " << score << endl;
    cout << " 0    1    2" << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            cout<<Bricks[v[j]].first[i][0];
            cout<<Bricks[v[j]].first[i][1];
            cout<<Bricks[v[j]].first[i][2];
            cout << "  ";
        }
        cout << endl;
    }
}
bool valid_place(int i, int j, char shapechar)
{
    switch(shapechar)
    {
        case('1'):
            if(i+2 < N && j+2 < N && grid[i][j] == 0 && grid[i+1][j] == 0 && grid[i+2][j] == 0 && grid[i+2][j+1] == 0 && grid[i+2][j+2] == 0)
                return true;
            else
                return false;
            case('2'):
                if(i+1 < N && j+1 < N && grid[i][j] == 0 && grid[i][j+1] == 0 && grid[i+1][j] == 0 && grid[i+1][j+1] == 0)
                    return true;
                else
                    return false;
                case('3'):
                    for(int k = i; k <= i+2; k++)
                    {
                        for(int l = j; l <= j+2; l++)
                        {
                            if(grid[k][l] == 1)
                                return false;
                        }
                    }
                    return true;
                    case('4'):
                        if(j+2 < N && grid[i][j] == 0 && grid[i][j+1] == 0 && grid[i][j+2] == 0)
                            return true;
                        else
                            return false;
                        case('5'):
                            if(grid[i][j] == 0)
                                return true;
                            else
                                return false;
                            case('6'):
                                if(j + 1 < N && grid[i][j] == 0 && grid[i][j+1] == 0)
                                    return true;
                                else
                                    return false;
                                case('7'):
                                    if(i+2 < N && j+2 < N && grid[i][j] == 0 && grid[i][j+1] == 0 && grid[i][j+2] == 0 && grid[i+1][j+2] == 0 && grid[i+2][j+2] == 0)
                                        return true;
                                    else
                                        return false;
                                    case('8'):
                                        if(i+1 < N && j+1 < N && grid[i][j] == 0 && grid[i+1][j] == 0 && grid[i][j+1] == 0)
                                            return true;
                                        else
                                            return false;
    }
}
void place_shape(int i, int j, char shapechar, int shapeIndex, vector<int>& idx)
{
    switch(shapechar)
    {
        case('1'):
            grid[i][j] = 1;
            grid[i+1][j] = 1;
            grid[i+2][j] = 1;
            grid[i+2][j+1] = 1;
            grid[i+2][j+2] = 1;
            break;
            case('2'):
                grid[i][j] = 1;
                grid[i][j+1] = 1;
                grid[i+1][j] = 1;
                grid[i+1][j+1] = 1;
                break;
                case('3'):
                    for(int k = i; k <= i+2; k++)
                    {
                        for(int l = j; l <= j+2; l++)
                        {
                            grid[k][l] = 1;
                        }
                    }
                    break;
                    case('4'):
                        grid[i][j] = 1;
                        grid[i][j+1] = 1;
                        grid[i][j+2] = 1;
                        break;
                        case('5'):
                            grid[i][j] = 1;
                            break;
                            case('6'):
                                grid[i][j] = 1;
                                grid[i][j+1] = 1;
                                break;
                                case('7'):
                                    grid[i][j] = 1;
                                    grid[i][j+1] = 1;
                                    grid[i][j+2] = 1;
                                    grid[i+1][j+2] = 1;
                                    grid[i+2][j+2] = 1;
                                    break;
                                    case('8'):
                                        grid[i][j] = 1;
                                        grid[i+1][j] = 1;
                                        grid[i][j+1] = 1;
                                        break;
    }
}
bool check_lose(vector<int> idx)
{
    int counter = 0;
    for(int k = 0; k < idx.size(); k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(valid_place(i, j, Bricks[k].second))
                    return false;
            }
        }
    }
    return true;
}
void check_ones()
{
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 1)
                counter++;
            else
            {
                counter = 0;
                break;
            }
        }
        if(counter == N)
        {
            for(int k = 0 ; k < N; k++)
            {
                grid[i][k] = 0;
            }
            counter = 0;
        }
    }
    counter = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[j][i] == 1)
                counter++;
            else
            {
                counter = 0;
                break;
            }
        }
        if(counter == N)
        {
            score += 10;
            for(int k = 0 ; k < N; k++)
            {
                grid[k][i] = 0;
            }
            counter = 0;
        }
    }
}
bool check_input(int i, int j, int shapeIndex, vector<int>idx)
{
    if(i >= 0 && i < N && j >= 0 && j < N && shapeIndex >= 0 && shapeIndex < 3 && valid_place(i,j,Bricks[idx[shapeIndex]].second))
        return true;
    return false;
}
void take_input(int &i, int &j, int &shapeIndex, vector<int>& idx)
{
    cout << "Enter Row Index" << endl;
    cin >> i;
    cout << "Enter Column Index" << endl;
    cin >> j;
    cout << "Enter shape Index" << endl;
    cin >> shapeIndex;
    if(!check_input(i, j, shapeIndex, idx))
    {
        cout << "Invalid Input" << endl;
        take_input(i,j,shapeIndex, idx);
    }
}
void play_game()
{
    vector<int> idx;
    int i,j;
    int shapeIndex;
    initialize();
    int counter = 3;
    idx = generate();
    while(true)
    {
        if(counter == 0)
        {
            idx = generate();
            counter = 3;
        }
        print_grid(idx);
        take_input(i,j,shapeIndex, idx);
        place_shape(i,j,Bricks[idx[shapeIndex]].second,shapeIndex,idx);
        counter--;
        check_ones();
        if(check_lose(idx))
        {
            cout << "You Lost" << endl;
            break;
        }
        auto del_ele = idx.begin()+shapeIndex;
        idx.erase(del_ele);
    }
}
int main()
{
    play_game();
}