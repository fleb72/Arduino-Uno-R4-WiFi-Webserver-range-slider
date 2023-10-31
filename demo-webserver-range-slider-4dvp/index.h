#ifndef INDEX_H
#define INDEX_H
//#include <SafeString.h>

//createSafeString(HTML_CONTENT, 1200, R""""(
const char* HTML_CONTENT = R""""(
<!DOCTYPE html>

<html lang="fr">
<head>
  <meta charset="UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1" >
  <title>Range slider Arduino Uno R4 WiFi</title>
  <link rel="stylesheet" href="style.css">
  <script src="javascript.js"></script>
</head>

<body onload="maj_onload()">
  <div class="slider">
    <input id="range1" type="range" min="0" max="100" step="5" value="0" oninput="rangeUpdate(this.value)">
    <p id="rangeValue">0</p>
  </div> 
</body> 

</html>
)"""";

#endif
