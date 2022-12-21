# CS 124 Project 5
# Wade Bradford

1.) Information about data set:
My data set is a set containing data regarding the stream stastics and profiles of 1000 streamers on Twitch.Tv over the course of one year. There are 11 attributes to each streamer including: streamer name, watch time (minutes), stream time (minutes), peak viewers, average viewers, followers, followers gained, views gained, partnership status, maturity status, and the language the streamer broadcasts in.

2.) Graphs:
![Separate Chaining Streamers Graph](https://user-images.githubusercontent.com/112721212/204923553-f1b0a3bf-27d1-4300-9bda-7752f5b91850.png)

In the separate chaining graph, the average number of reads per insertion decreases as the size of the table increases.

![Blue Photo Modern Listing Presentation](https://user-images.githubusercontent.com/112721212/204933299-6639ac10-27bc-4ae6-a00f-5947cb487029.png)

In open addressing (quadratic probing) there is less of a pattern. The number of reads continues to grow smaller as the table size increases, though the relationship between the getKey functions is unclear.

3.) Which getKey function works best?
In separate chaining the amount of reads with each getKey function (getStreamer/getStreamerOther) is similiar with smaller sized tables, but the difference is more noticeable as the table size grows with the getStreamerOther function having a slightly larger average. In this case, the getStreamer function works better as it has less reads.

In open addressing, it is harder to determine which getKey function works best. For larger tables, it is still the getStreamer function that has less reads. However, as the table gets smaller, the getStreamer function ends up having more reads than the getStreamerOther functionn.

4.) Collision Detection conclusions:
On my data set, separate chaining works more efficently than open addressing (quadratic probing) as each of the read averages per insertion are less than the averages for open adressing. This is in comparison with the same size tables and getKey functions.
