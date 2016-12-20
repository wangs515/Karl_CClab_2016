
function initMap() {
   myLat = document.getElementById('currentLat').value;
   myLng = document.getElementById('currentLng').value;
   console.log(myLat);
   console.log(myLng);
// lat = $('#currentLat').val();
// lng = $('#currentLng').val();

    var myLatLng = {lat: Number(myLat) , lng: Number(myLng) };
    console.log(myLatLng);
    // Create a map object and specify the DOM element for display.
    var map = new google.maps.Map(document.getElementById('map'), {
        center: myLatLng,
        scrollwheel: false,
        zoom: 4
        });

    // Create a marker and set its position.
    var marker = new google.maps.Marker({
        map: map,
        position: myLatLng,
        title: 'Hello World!'
        });
}

function init(){

    $('#submit').click(function(){
             initMap();
    });
}

$(document).ready(function(){
   init();
});