/*
 * Operator overloading exercise. Source: https://youtu.be/BnMnozsSPmw
 * (CodeBeauty).
 */

#include <iostream>
#include <string>
#include <list>

struct YouTubeChannel {
    std::string Name;
    int SubscribersCount;


    YouTubeChannel(std::string name, int subscriberCount) {
        Name = name;
        SubscribersCount = subscriberCount;
    }

    bool operator==(const YouTubeChannel&channel) const {
        return  this->Name == channel.Name;
    }
};

/*
    * GLOBAL function that takes 2 parameters, COUT, from 'ostream' library
    * and an object from our struct 'YouTubeChannel'.
 */
std::ostream& operator<<(std::ostream& COUT, YouTubeChannel& ytChannel) {
    COUT << "Name: " << ytChannel.Name << std::endl;
    COUT << "Subscribers: "<< ytChannel.SubscribersCount << std::endl;

    return COUT;
}

struct MyCollection {
    std::list<YouTubeChannel>myChannels;

    /*
     * This function is used to add a channel to the collection
     * MEMBER function of struct MyCollection. Takes only one parameter
     * YouTubeChannel.
     */
    void operator+=(YouTubeChannel& channel) {
        this->myChannels.push_back(channel);
    }
    void operator-=(YouTubeChannel& channel) {
        this->myChannels.remove(channel);
    }
};

std::ostream& operator<<(std::ostream& COUT, MyCollection& myCollection) {
    for(YouTubeChannel ytChannel:myCollection.myChannels)
        COUT << ytChannel << std::endl;
    return  COUT;
}

int main() {

    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);
//    std::cout << yt1 << yt2;
    std::cout << yt1;
    //Calling the operator function as a normal global function:
    operator<<(std::cout, yt1); //This way is less used


    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;
    std::cout << "Print the collection: " << std::endl;
    std::cout << myCollection;



    return 0;
}
