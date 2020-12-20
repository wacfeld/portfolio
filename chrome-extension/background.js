//key is AIzaSyCNrRdxOBMs5-lNyjIhCZrgmwcolNwksko
//cx code is 001862162715626624364:bhhjyvwxa60
//GET https://www.googleapis.com/customsearch/v1?key=AIzaSyCNrRdxOBMs5-lNyjIhCZrgmwcolNwksko&cx=001862162715626624364:bhhjyvwxa60&q=PUT_SEARCH_HERE
/*

chrome.browserAction.onClicked.addListener(function(tab) {
  // Send a message to the active tab
  chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
    var activeTab = tabs[0];
    chrome.tabs.sendMessage(activeTab.id, {"message": "clicked_browser_action"});
  });
});

// This block is new!
chrome.runtime.onMessage.addListener(
  function(request, sender, sendResponse) {
    if( request.message === "open_new_tab" ) {
      chrome.tabs.create({"url": request.url});
    }
  }
);
*/

function httpGet(query)
{
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open( "GET", "https://www.googleapis.com/customsearch/v1?key=AIzaSyCNrRdxOBMs5-lNyjIhCZrgmwcolNwksko&cx=001862162715626624364:bhhjyvwxa60&q="+query.replace(/[^a-zA-Z0-9\s]/g,"").replace(/\s/g,"+"), false ); // false for synchronous request
    xmlHttp.send( null );
    return xmlHttp.responseText;
}

chrome.runtime.onMessage.addListener(
    function(request, sender, sendResponse) {
        var obj = JSON.parse(httpGet(request.greeting));
        var title = obj.items[0].title;
        sendResponse({farewell: title});
    }
);
