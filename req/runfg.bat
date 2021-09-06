SET PATH=C:\Program Files\FlightGear 2018.3.6

SET FG_ROOT=%PATH%\data

SET FG_SCENERY=%PATH%\data\Scenery;%PATH%\scenery;%PATH%\terrasync"

"%PATH%\bin\fgfs" --aircraft=missile --fdm=null --enable-auto-coordination --native-fdm=socket,in,30,localhost,5502,udp --disable-clouds --disable-clouds3d --shading-flat --start-date-lat=2004:06:01:19:00:00 --visibility-miles=10 --disable-sound --disable-freeze --airport=TLV --runway=08L --heading=0 --offset-distance=0 --offset-azimuth=0 --enable-rembrandt --config="%PATH%\data\Aircraft\missile\FlightGearConfig.xml"