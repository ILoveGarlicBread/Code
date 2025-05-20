# Problem with HTTP/1.1
Head of Line blocking
One request perconnection (limited parallelism)
Impact on performance

To understand why multiplexing is useful, let’s look at HTTP/1.1.
In HTTP/1.1, each request-response pair needs its own connection, or at best, 
you could have a few in parallel.
But here’s the catch: If you want to load a modern website, you 
may need dozens of requests — for HTML, CSS, JavaScript, images, fonts, etc. All sent in order.
The problem is if one request is slow or lost, everything else behind it got delayed.
These requests end up getting stuck in a queue — this is called head-of-line blocking. 
And it makes websites load more slowly. To combat this. HTTP1.1 may create multiple tcp connections to 
transfer those requests or responses in parallel. But this increase complexity,
as you know TCP has to go through a handshake process for each connection, which add latency, 
and also more connections means more resources used on both client and server sides.


# What is Multiplexing
Definition
Anology
How it solve HTTP1.1's problems 
Does head of line blocking still occur?

To solve that, HTTP/2 uses multiplexing.
Think of it like a multi-lane highway instead of a one-lane road. 
With HTTP/1.1, you had to wait behind slow traffic, sharing a single lane with others. 
With HTTP/2 multiplexing, everyone gets their own lane and moves side by side, even if some are slower than the others.
This means the browser can send multiple requests at once — and get multiple responses in parallel — all in one TCP connection.
In simple terms, multiplexing means combining multiple streams into one connection. 
Does this fully solve Hob?
Sort of
it solve hob only  on application layer
Hob still occure on transport layer due to TCP's sequential nature.


# How does it work
Single TCP connection
Streams and frames
Interleaving requests and response

First, HTTP/2 uses a single TCP connection between the browser and the server.
Inside that connection, it creates multiple streams — and each stream can carry one request and its response.
These streams are broken into frames — small chunks of data — that are sent over the connection.
To know which frames belong to which streams, HTTP2 use streams IDs.
Streams IDS are 32 bit numbers that are store in each frame header.
These frames can be sent out of order, TCP will ensure they show up at the receiver in the exact order they are sent.
When the server get a HEADER frame, it creates a new stream using the same stream ID as the request.
It starts by sending back its own HEADERS frame, which contains the response status and headers.
After that, the response body is sent in DATA frames.
Thanks to multiplexing, the server can interleave frames from multiple streams, 
sending chunks of different responses over the same connection simultaneously.


# Demonstration in wireshark
Now I'm gonna show you an example in wireshark.

# Resourses
https://ably.com/topic/http2
https://victoriametrics.com/blog/go-http2/
https://celaldogan2010.medium.com/analyzing-http-2-with-wireshark-64c15793e91
https://rovity.io/what-is-http-2/
https://www.catchpoint.com/http3-vs-http2

These are the sources that I used for this presentation, you can read them for more
in depth information about multiplexing or HTTP/2 in general.
