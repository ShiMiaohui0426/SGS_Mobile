INCLUDEPATH += /opt/ros/kinetic/include
DEPENDPATH +=   /opt/ros/kinetic/include
#LIBS +=  -l:/usr/lib/x86_64-linux-gnu/libboost_thread.so
#LIBS +=  -l:/usr/lib/x86_64-linux-gnu/libpthread.so

LIBS += -L/opt/ros/kinetic/lib -lroscpp -lrospack -lpthread -lrosconsole -lrosconsole_log4cxx -lrosconsole_backend_interface -lxmlrpcpp -lroscpp_serialization -lrostime  -lcpp_common  -lroslib -ltf  -lyaml-cpp -lkdl_conversions
