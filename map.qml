import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle{
    id: window
    property double oldLat: 42.984908
    property double oldLng: -81.245303
    property Component comMarker: mapMarker

    Plugin{
        id:mapPlugin
        name:"osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin:mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 10

        MouseArea {
            anchors.fill: parent
            onPressAndHold: {
                var crd = mapView.toCoordinate(Qt.point(mouseX, mouseY))
                console.log(crd.latitude, crd.longitude, crd.altitude);

                onAddPoint(crd.latitude, crd.longitude);
            }
        }
    }

    signal onAddPoint(var latitude, var longitude);

    signal onPointClicked(var pointId);

    function doAddPoint(pointId, latitude, longitude) {
        var item = comMarker.createObject(window, {  coordinate: QtPositioning.coordinate(latitude, longitude), pointId:pointId  })
        mapView.addMapItem(item)
    }

    Component {
            id: mapMarker
            MapQuickItem {
                id: markerImg
                anchorPoint.x: image.width/4
                anchorPoint.y: image.height
                coordinate: position
                property int pointId: -1

                sourceItem: Image {
                    id: image
                    source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            onPointClicked(pointId);
                        }
                    }
                }
            }
        }


}
