console.log("hi");
var x = 0;
var things = [0];
var y;
setInterval(function() {
    $(".title-card.is-bob-open").each(function(){
        x = $(this).find("a").attr("aria-label");
        y = $(this)
    });
    if(things.indexOf(x)<0) {
        things.push(x);
        chrome.runtime.sendMessage({greeting: x}, function(response) {
            y.append("<div>"+response.farewell+"</div>");
            console.log(response.farewell);
        });

    }
},1000);
