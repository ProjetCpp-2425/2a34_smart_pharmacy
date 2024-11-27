import QtQuick
import QtLocation
import QtPositioning

Rectangle
{
   id:window
   property double latitude: 51.5072
   property double   longitude: 0.1276

   property Component locationmarker: locmarker
   Plugin
   {
       id:googlemapview
       name: "osm"
   }

   Map {
       id: mapview
       anchors.fill: parent
       plugin: googlemapview
       center: QtPositioning.coordinate(latitude, longitude)
       zoomLevel: 16

       //gesture.enabled: true // Enables panning and zoom gestures
       minimumZoomLevel: 5   // Set minimum zoom level
       maximumZoomLevel: 20  // Set maximum zoom level
   }


   function setCenterPosition(lati,longi)
   {
       mapview.pan(latitude - lati,longitude - longi)
       latitude=lati
       longitude=longi
   }
   function setLocationMarking(lati, longi) {
       console.log("Creating marker at:", lati, longi);

       var item = locationmarker.createObject(window, {
           coordinate: QtPositioning.coordinate(lati, longi)
       });

       if (item === null) {
           console.error("Failed to create marker!");
           return;
       }

       console.log("Marker created:", item);
       mapview.addMapItem(item);
   }

   Component
   {
       id:locmarker
       MapQuickItem
       {
           id:markerImg
           anchorPoint.x: image.width/4
           anchorPoint.y: image.height
           coordinate: position
           sourceItem: Image {
               id: image
               width:20
               height:20
               source: "https://www.pngarts.com/files/3/Map-Marker-Pin-PNG-Image-Background.png"
           }
       }
   }
}
