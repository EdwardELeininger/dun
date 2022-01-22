mainCanvas = document.getElementById("mainCanvas");
mainCanvas.width = innerWidth;
mainCanvas.height = innerHeight;
console.log("ohaithar");
console.log(mainCanvas);

window.addEventListener('resize', function(event){
    mainCanvas.width = innerWidth;
    mainCanvas.height = innerHeight;
    //TODO request new frame from server!!
    console.log(mainCanvas);
}, true);
let GAME = true;
while(GAME){
    //check for updates to the viewport
    if(newViewportBuffer){
        //if there are lets draw them, updates should have
        //startX, startY, endX, endY
        //they should be RGBA values in the form of:
        //X, Y, R, G, B, A
        //start with a sanity check and make sure that the update is not out of bounds
        if(viewportBuffer.endX > mainCanvas.width || viewportBuffer.endY > mainCanvas.height);
        else(){
            //draw loop
            updateViewport(viewportBuffer);
        }
    //if canvas width > height split vertically, else split horizontally.
    }

    //if browser is a mobile device render mobile ui, else listen for keyboard events
    //send user input to server
}
