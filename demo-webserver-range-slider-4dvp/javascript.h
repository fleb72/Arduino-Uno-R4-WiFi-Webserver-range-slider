#ifndef JAVASCRIPT_H
#define JAVASCRIPT_H
//#include <SafeString.h>

/* constante JAVASCRIPT avec le code JavaScript */
//createSafeString(JAVASCRIPT_CONTENT, 1200, R""""(
const char* JAVASCRIPT_CONTENT = R""""(  
  function refresh(value) {
    document.getElementById("rangeValue").innerText = value;
  }

  function rangeUpdate(value) {
    var url = "/range?v=";
    url += value;
    console.log(url);
    refresh(value);
   
    fetch(url)
    .catch(error => {
        console.log(error);
      })       
    }

  function maj_onload() {
    fetch("/maj_onload")
    .then(res => res.json())
    .then(data => {
        console.log(data);
        document.getElementById("range1").value = data.value;
        refresh(data.value);
      })
    .catch(error => {
        console.log(error);
      })   
    }
)"""";

#endif
