                +---------------------+
                | open TCP connection |
                +---------------------+
                           |
                           v
                    +---------------+
                    | send initial  |<-------------------------+
                    | stream header |                          ^
                    +---------------+                          |
                           |                                   |
                           v                                   |
                   +------------------+                        |
                   | receive response |                        |
                   | stream header    |                        |
                   +------------------+                        |
                           |                                   |
                           v                                   |
                    +----------------+                         |
                    | receive stream |                         |
+------------------>| features       |                         |
^   {OPTIONAL}      +----------------+                         |
|                          |                                   |
|                          v                                   |
|       +<-----------------+                                   |
|       |                                                      |
|    {empty?} ----> {all voluntary?} ----> {some mandatory?}   |
|       |      no          |          no         |             |
|       | yes              | yes                 | yes         |
|       |                  v                     v             |
|       |           +---------------+    +----------------+    |
|       |           | MAY negotiate |    | MUST negotiate |    |
|       |           | any or none   |    | one feature    |    |
|       |           +---------------+    +----------------+    |
|       v                  |                     |             |
|   +---------+            v                     |             |
|   |  DONE   |<----- {negotiate?}               |             |
|   +---------+   no       |                     |             |
|                     yes  |                     |             |
|                          v                     v             |
|                          +--------->+<---------+             |
|                                     |                        |
|                                     v                        |
+<-------------------------- {restart mandatory?} ------------>+
               no                                     yes
