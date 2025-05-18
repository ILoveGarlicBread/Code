# Problem with HTTP/1.1
Head of Line blocking
One request perconnection (limited parallelism)
Impact on performance

To understand why multiplexing is useful, let’s look at HTTP/1.1.
In HTTP/1.1, each request-response pair needs its own connection, or at best, 
you could have a few in parallel.
But here’s the catch: If you want to load a modern website, you 
may need dozens of requests — for HTML, CSS, JavaScript, images, fonts, etc.
The problem is if one request is slow, everything else behind it got delayed.
These requests end up getting stuck in a queue — this is called head-of-line blocking. 
And it makes websites load more slowly. To combat this. HTTP1.1 may create multiple tcp connections to 
transfer those requests or responses in parallel. But this increase complexity,
as you know TCP has to go through a handshake process for each connection, which add latency, 
and also more connections means more resources used on both client and server sides.


# What is Multiplexing
Definition
Anology
How it solve HTTP1.1's problems 
Highway Lane anology

To solve that, HTTP/2 uses multiplexing.
In simple terms, multiplexing means combining multiple signals or streams into one.
Think of it like a multi-lane highway instead of a one-lane road. 
With HTTP/1.1, you had to wait behind slow traffic, sharing a single lane with others. 
With HTTP/2 multiplexing, everyone gets their own lane and moves side by side, even if some are slower than the others.
This means the browser can send multiple requests at once — and get multiple responses in parallel — all in one connection.

# How does it work
Single TCP connection
Streams and frames
Interleaving requests and response
Deck of Card analogy

First, HTTP/2 uses a single TCP connection between the browser and the server.
Inside that connection, it creates multiple streams — and each stream can carry one request and its response.
These streams are broken into frames — small chunks of data — that are interleaved as they travel over the network.
The server and browser can send these frames out of order, the frames that are receives first will be cached and 
all of them are reassembled 
To know which frames belong to which streams, HTTP2 use streams IDs.
Think of a deck of card, each frame is a different suit like hearts or spades. 
When we shuffle the deck, the cards are mixed, but we can still tell which card belongs to which suit.

# Demonstration in wireshark
Now I'm gonna show you an example in wireshark.
By default you won't be able to view http2 in wireshark, you have to set up tls decription in the settings first.

# Resourses
https://ably.com/topic/http2
https://victoriametrics.com/blog/go-http2/
https://www.mnot.net/blog/2019/10/13/h2_api_multiplexing
https://celaldogan2010.medium.com/analyzing-http-2-with-wireshark-64c15793e91

These are the sources that I used for this presentation, you can read them for more
in depth information about multiplexing or HTTP/2 in general.
