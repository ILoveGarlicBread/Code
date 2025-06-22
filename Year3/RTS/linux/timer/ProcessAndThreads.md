# A.
My shell script, just infinite loops
```
#!/bin/bash
# filename: test.sh
for (( ; ; ))
do
   echo "infinite loops [ hit CTRL+C to stop]"
done

```
I used the following command to put everything in this file:
```
 ps -u $(whoami) -o ppid,pid,psr,sgi_p,pcpu,comm,policy,rtprio,pri,nice,time,c,f,nwchan,cmd,pmem,maj_flt,min_flt,sz >> ProcessAndThreads.md
```
Meaning of the options:
ppid:	Parent Process ID
pid:	Process ID
psr:	Processor number the process is currently assigned to (CPU core)
sgi_p:	Project ID 
pcpu:	% of CPU usage
comm:	Command name 
policy:	Scheduling policy 
rtprio:	Real-time priority (if using real-time scheduling)
pri:	Priority of the process
nice:	Niceness value (affects priority)
time:	Total CPU time used
c:	Processor utilization counter (obsolete or rarely meaningful)
f:	Flags (internal kernel process flags)
wchan:	Wait channel — what the process is waiting on (if sleeping)
cmd:	Full command line
pmem:	% of memory used
maj_flt:	Number of major page faults (requiring disk access)
min_flt:	Number of minor page faults (handled from memory)
sz:	Virtual memory size of the process in pages

Result:
Use the search function in nvim I found test.sh on line 135
```
   PPID     PID PSR P %CPU COMMAND         POL RTPRIO PRI  NI     TIME  C F  WCHAN CMD                         %MEM  MAJFL  MINFL    SZ
      1    2066  12 *  0.0 systemd         TS       -  19   0 00:00:00  0 4      - /usr/lib/systemd/systemd --  0.0      0   1929  5498
   2066    2068  10 *  0.0 (sd-pam)        TS       -  19   0 00:00:00  0 5      - (sd-pam)                     0.0      0     51  5684
   2066    2077   1 *  0.0 gnome-keyring-d TS       -  19   0 00:00:00  0 0      - /usr/bin/gnome-keyring-daem  0.0      0    960 45505
   2066    2085   2 2 50.3 tmux: server    TS       -  19   0 00:08:37 50 1      - /usr/bin/tmux new-session -  0.2      0 1695014 9963
   2066    2086  10 *  0.0 dbus-broker-lau TS       -  19   0 00:00:00  0 0      - /usr/bin/dbus-broker-launch  0.0      0    711  2028
   2086    2088  10 *  0.0 dbus-broker     TS       -  19   0 00:00:00  0 0      - dbus-broker --log 4 --contr  0.0      0    640  1541
   1994    2350   7 *  0.0 gdm-wayland-ses TS       -  19   0 00:00:00  0 4      - /usr/lib/gdm-wayland-sessio  0.0      0    537 41650
   2350    2358  10 *  0.0 gnome-session-b TS       -  19   0 00:00:00  0 0      - /usr/lib/gnome-session-bina  0.1      1   1898 76622
   2066    2446   8 *  0.0 gnome-session-c TS       -  19   0 00:00:00  0 0      - /usr/lib/gnome-session-ctl   0.0      0    707 21673
   2066    2463   2 *  0.0 gnome-session-b TS       -  19   0 00:00:00  0 0      - /usr/lib/gnome-session-bina  0.1      1   2443 148503
   2066    2538   3 * 13.6 gnome-shell     TS       -  19   0 00:02:19 13 0      - /usr/bin/gnome-shell         2.6     37 281287 1769545
   2066    2574   7 *  0.0 gvfsd           TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd               0.0      1   1503 80988
   2066    2604  10 *  0.0 gvfsd-fuse      TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-fuse /run/us  0.0      0    374 99174
   2066    2741   0 *  0.0 at-spi-bus-laun TS       -  19   0 00:00:00  0 0      - /usr/lib/at-spi-bus-launche  0.0      0    921 95210
   2741    2751  14 *  0.0 dbus-broker-lau TS       -  19   0 00:00:00  0 0      - /usr/bin/dbus-broker-launch  0.0      0    239  1996
   2751    2752   0 *  0.0 dbus-broker     TS       -  19   0 00:00:00  0 0      - dbus-broker --log 4 --contr  0.0      0    166  1066
   2066    2768  14 *  0.0 at-spi2-registr TS       -  19   0 00:00:00  0 0      - /usr/lib/at-spi2-registryd   0.0      0    829 42036
   2066    2817   8 *  0.0 xdg-permission- TS       -  19   0 00:00:00  0 0      - /usr/lib/xdg-permission-sto  0.0      0    740 76435
   2066    2901  12 *  0.0 gjs             TS       -  19   0 00:00:00  0 0      - /usr/bin/gjs -m /usr/share/  0.1      0   2997 682986
   2066    2912  14 *  0.0 gsd-a11y-settin TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-a11y-settings   0.0      0    837 60253
   2066    2913   5 *  0.0 gsd-color       TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-color           0.1      0   2170 112092
   2066    2914  14 *  0.0 gsd-datetime    TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-datetime        0.0      0   1169 72554
   2066    2915   1 *  0.0 gsd-housekeepin TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-housekeeping    0.0      0   1012 96269
   2066    2917   7 *  0.0 gsd-keyboard    TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-keyboard        0.1      0   2084 111797
   2066    2918   5 *  0.0 gsd-media-keys  TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-media-keys      0.1      0   2322 167700
   2066    2919   9 *  0.0 gsd-power       TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-power           0.1      0   2203 130528
   2066    2924   8 *  0.0 gsd-print-notif TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-print-notifica  0.0      0   1118 80157
   2066    2928   1 *  0.0 gsd-rfkill      TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-rfkill          0.0      0    836 113472
   2066    2931   7 *  0.0 gsd-screensaver TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-screensaver-pr  0.0      0    766 41689
   2066    2933  13 *  0.0 gsd-sharing     TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-sharing         0.0      0   1118 115040
   2066    2937   4 *  0.0 gsd-smartcard   TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-smartcard       0.0      0   1013 95565
   2066    2939   1 *  0.0 gsd-sound       TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-sound           0.0      0   1003 63248
   2066    2944   9 *  0.0 gsd-usb-protect TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-usb-protection  0.0      0    906 132961
   2066    2957  13 *  0.0 gsd-wacom       TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-wacom           0.1      0   2379 112196
   2066    3002  13 *  0.0 gsd-printer     TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-printer         0.1      0   1034 113159
   2463    3043  10 *  0.0 firewall-applet TS       -  19   0 00:00:00  0 0      - /usr/bin/python /usr/bin/fi  0.6     31  11182 152836
   2463    3048   4 *  0.1 blueman-applet  TS       -  19   0 00:00:01  0 0      - /usr/bin/python /usr/bin/bl  0.4      3  10719 159721
   2463    3054   9 *  0.0 gsd-disk-utilit TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-disk-utility-n  0.0      1    533 76803
   2066    3062  14 *  0.0 gjs             TS       -  19   0 00:00:00  0 0      - /usr/bin/gjs -m /usr/share/  0.1      0   2992 682981
   2538    3177   5 *  1.6 Xwayland        TS       -  19   0 00:00:16  1 0      - /usr/bin/Xwayland :0 -rootl  0.7      1  16642 282963
   2085    3273   0 *  0.6 zsh             TS       -  19   0 00:00:06  0 0      - /bin/zsh                     0.1      0 304625  6289
   2066    3305   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0    265  2556
   2066    3361   0 *  0.0 gvfs-udisks2-vo TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfs-udisks2-volum  0.1      2   1430 108467
   2066    3477  10 *  0.0 gvfs-mtp-volume TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfs-mtp-volume-mo  0.0      0    805 76577
   2066    3531   5 *  0.0 gvfs-gphoto2-vo TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfs-gphoto2-volum  0.0      2    863 77048
   2066    3532   8 *  0.0 xdg-desktop-por TS       -  19   0 00:00:00  0 0      - /usr/lib/xdg-desktop-portal  0.1      0   1838 241534
   2066    3589   6 *  0.0 xdg-document-po TS       -  19   0 00:00:00  0 0      - /usr/lib/xdg-document-porta  0.0      0    817 153203
   2066    3600  14 *  0.0 gvfs-afc-volume TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfs-afc-volume-mo  0.0      0    957 96878
   2066    3664   5 *  0.0 dconf-service   TS       -  19   0 00:00:00  0 0      - /usr/lib/dconf-service       0.0      0    941 41061
   2066    3737   8 *  0.0 pipewire        TS       -  30 -11 00:00:00  0 0      - /usr/bin/pipewire            0.0      0   2216 25474
   2066    3738   0 *  0.0 wireplumber     TS       -  30 -11 00:00:00  0 0      - /usr/bin/wireplumber         0.2      0   5715 190810
   2066    3743  15 *  0.0 pipewire-pulse  TS       -  30 -11 00:00:00  0 0      - /usr/bin/pipewire-pulse      0.0      0   1577 24967
   2066    3889  15 *  0.0 xdg-desktop-por TS       -  19   0 00:00:00  0 0      - /usr/lib/xdg-desktop-portal  0.2      0   4612 173735
   2066    4240   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0    116  3519
   2066    4241  13 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0     61  3515
   3305    4243   9 *  0.0 gitstatusd-linu TS       -  19   0 00:00:00  0 0      - /home/lam/.cache/gitstatus/  0.0      0    268 51296
   2066    4340   8 *  0.1 blueman-tray    TS       -  19   0 00:00:01  0 0      - /usr/bin/python /usr/bin/bl  0.3      0   7558 120955
   2066    4400   0 *  0.0 gsd-xsettings   TS       -  19   0 00:00:00  0 0      - /usr/lib/gsd-xsettings       0.4      1   6397 257009
   2538    4475  10 *  0.0 mutter-x11-fram TS       -  19   0 00:00:00  0 0      - /usr/lib/mutter-x11-frames   0.8      0  23654 436808
   2574    4537  10 *  0.0 gvfsd-http      TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-http --spawn  0.1      3   3268 140995
   2066    4550   0 *  0.0 xdg-desktop-por TS       -  19   0 00:00:00  0 0      - /usr/lib/xdg-desktop-portal  0.2      0   3554 114128
   2538    4581  10 *  0.3 nvidia-smi      TS       -  19   0 00:00:03  0 0      - nvidia-smi --query-gpu=name  0.1      0   1356 41546
   2538    4875  10 *  6.3 zen-bin         TS       -  19   0 00:01:04  6 0      - /opt/zen-browser-bin/zen-bi  3.3   2453 635823 3029320
   4875    4972   5 *  0.0 Socket Process  TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.2      2   3151 68108
   4875    4990   5 *  0.0 Privileged Cont TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.9      5  11532 640313
   4875    4995  15 *  0.0 RDD Process     TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  1.0      2  22715 256813
   4875    5039   0 *  0.0 Isolated Web Co TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.6      0   6858 637087
   4875    5043   4 *  1.9 Isolated Web Co TS       -  19   0 00:00:19  1 4      - /opt/zen-browser-bin/zen-bi  1.7      5 386170 741540
   4875    5085   7 *  0.0 Web Content     TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.8      1  10833 638582
   4875    5132   8 *  1.1 WebExtensions   TS       -  19   0 00:00:11  1 4      - /opt/zen-browser-bin/zen-bi  1.5      7 300446 6013067
   4875    5261   0 *  0.0 Utility Process TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.3      0   4470 134008
   4875    5277  12 *  0.2 Isolated Web Co TS       -  19   0 00:00:02  0 4      - /opt/zen-browser-bin/zen-bi  1.1      2  33940 664047
   4875    5288  14 *  0.2 Isolated Web Co TS       -  19   0 00:00:02  0 4      - /opt/zen-browser-bin/zen-bi  1.2      0  57643 1738786
   2066    6039  12 *  0.0 gvfsd-metadata  TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-metadata      0.0      0   1011 42024
   2538    6937  13 13 39.2 kitty          TS       -  19   0 00:05:56 39 0      - /usr/bin/kitty               0.8      5  15567 328542
   6937    6957  11 *  0.0 kitten          TS       -  19   0 00:00:00  0 0      - /usr/bin/kitten __atexit__   0.1      3   1404 496539
   6937    6959   6 *  0.1 zsh             TS       -  19   0 00:00:01  0 0      - /bin/zsh                     0.0      0  51515  3857
   2066    7113   4 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0    122  3498
   2066    7114   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0     61  3494
   2066    7117   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.0      0    265  3556
   7117    7122  10 *  0.0 gitstatusd-linu TS       -  19   0 00:00:00  0 0      - /home/lam/.cache/gitstatus/  0.0      0    158  1706
   6959    7981   8 *  0.0 tmux: client    TS       -  19   0 00:00:00  0 0      - tmux attach-session -t home  0.0      0    323  2466
   2066   10506   0 *  2.1 nautilus        TS       -  19   0 00:00:17  2 0      - /usr/bin/nautilus --gapplic  1.5     13  21434 665713
   2574   10510  12 *  0.0 gvfsd-trash     TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-trash --spaw  0.1      0   1321 171644
   2066   10530   5 *  0.0 localsearch-3   IDL      0   0   - 00:00:00  0 0      - /usr/lib/localsearch-3       0.1      1  26183 181988
   2574   10559  12 *  0.0 gvfsd-recent    TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-recent --spa  0.0      0   1225 99840
   2574   10560  10 *  0.0 gvfsd-network   TS       -  19   0 00:00:00  0 0      - /usr/lib/gvfsd-network --sp  0.0      0    793 99676
   2085   11931   6 *  0.3 zsh             TS       -  19   0 00:00:03  0 0      - -zsh                         0.0      0 270127  3938
   2066   12139   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0    122  3521
   2066   12140  10 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0     62  3517
   2066   12143  13 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0    263  3545
  12143   12148  12 *  0.0 gitstatusd-linu TS       -  19   0 00:00:00  0 0      - /home/lam/.cache/gitstatus/  0.0      0    275 51297
   4875   25174   4 *  2.0 Isolated Web Co TS       -  19   0 00:00:12  2 4      - /opt/zen-browser-bin/zen-bi  1.9      0 133779 707897
   4875   25579  13 *  0.0 Web Content     TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.5      0   5377 634751
   4875   25584  15 *  0.0 Web Content     TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.5      0   5364 634751
  11931   40960   7 7 99.3 test.sh         TS       -  19   0 00:08:03 99 0      - /bin/bash ./test.sh          0.0      0    210  1866
   4875   47846  12 *  0.0 Web Content     TS       -  19   0 00:00:00  0 4      - /opt/zen-browser-bin/zen-bi  0.5      0   5359 635007
   2085   50913  11 *  0.4 zsh             TS       -  19   0 00:00:01  0 0      - -zsh                         0.0      0  39581  3805
   2066   50979   0 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0    247  2803
   2066   51124  14 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0    119  3554
   2066   51125  12 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - -zsh                         0.0      0     63  3550
  50979   51127   4 *  0.0 gitstatusd-linu TS       -  19   0 00:00:00  0 0      - /home/lam/.cache/gitstatus/  0.0      0    270 51293
  50913   51695  12 *  0.0 yazi            TS       -  19   0 00:00:00  0 0      - yazi --cwd-file=/tmp/yazi-c  0.2      0   1794 422984
  51695   52392  14 *  0.0 nvim            TS       -  19   0 00:00:00  0 0      - /nix/store/dbs8qsz808swc85x  0.0      0    856  3059
  52392   52394   4 *  0.8 nvim            TS       -  19   0 00:00:02  0 0      - /nix/store/dbs8qsz808swc85x  0.3      2  72552 88546
   3273   61945  14 *  0.0 zsh             TS       -  19   0 00:00:00  0 1      - /bin/zsh                     0.1      0    113  6325
   3273   61948  11 11 0.0 ps              TS       -  19   0 00:00:00  0 4      - ps -u lam -o ppid,pid,psr,s  0.0      0    562  2526
```
# B
pstree: Display a tree process
Good for seeing the hierarchy of processes
```
pstree –acghlpsUu
```
I would put the output in this file if it wasn't over 1000 lines :)
The meaning of the flags:
-a:	Show command line arguments for each process
-c:	Disable compaction of identical branches (i.e., show all, no merging)
-g:	Show process group IDs
-h:	Highlight the current process and its ancestors
-l:	Don’t truncate long lines or command names
-p:	Show PIDs (Process IDs)
-s:	Show parent processes of the specified process (with hierarchy)
-U:	Show UID (user ID) of each process
-u:	Show username (real user)

# C.
This command list all proccesses with full format then filter with grep to show only line with my username
```
ps -ef|grep $(whoami)
```

A minor page fault happens when a proccess try to access data
that is already in RAM but isn't yet map to the process virtual memory,
the OS only need to update the page table to fix this.
