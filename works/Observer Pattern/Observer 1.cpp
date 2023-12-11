#include <iostream>
#include <list>
using namespace std;

class Observer {
public:
    virtual void update(string comment) = 0;
};

class Subscriber : Observer {
    string name;
public:
    void update(string comment) { cout << name << " : " << comment << endl; }
    Subscriber(string n) : name(n) {}
};

class Youtuber {
    list<Subscriber*> subscribers;
public:
    void addSubscriber(Subscriber* s) { subscribers.push_back(s); }
    void removeSubscriber(Subscriber* s)
    {
        for (auto i = subscribers.begin(); i != subscribers.end(); ++i)
        {
            if (*i == s) {
                subscribers.erase(i);
                break;
            }
        }
    }
    void notify(string comment) { for (auto i : subscribers) { i->update(comment); } }
};

int main()
{
    Youtuber OliverSam;
    Subscriber song("송보현");
    Subscriber yu("유동수");
    Subscriber kim("김영한");

    OliverSam.addSubscriber(&song);
    OliverSam.addSubscriber(&yu);
    OliverSam.addSubscriber(&kim);

    OliverSam.notify("댓글 알림");

    OliverSam.removeSubscriber(&yu);
    OliverSam.removeSubscriber(&kim);

    OliverSam.notify("영상 올림");
}
