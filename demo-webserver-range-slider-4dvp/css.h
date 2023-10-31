#ifndef CSS_H
#define CSS_H
//#include <SafeString.h>

/* constante CSS_CONTENT avec le code de la feuille de style CSS
d'après How to Create a Range Slider in HTML + CSS, par Danielle Ellis (juillet 2023)
https://blog.hubspot.com/website/html-slider
*/

//createSafeString(CSS_CONTENT, 6600, R""""(
const char* CSS_CONTENT = R""""(  
body {background: linear-gradient(to right, red, yellow);}

.slider {position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%,-50%);
        width: 270px;
        height: 60px;
        padding: 30px;
        padding-left: 40px;
        background: #fcfcfc;
        border-radius: 20px;
        display: flex;
        align-items: center;
        box-shadow: 0px 15px 40px #7E6D5766;}
        
.slider p {font-size: 26px;
          font-weight: 600;
          font-family: Open Sans;
          padding-left: 30px;
          color: black;}
          
.slider input[type="range"] {-webkit-appearance:none !important;
                              width: 200px;
                              height: 2px;
                              background: black;
                              border: none;
                              outline: none;}
                              
.slider input[type="range"]::-webkit-slider-thumb {-webkit-appearance: none !important;
                                                    width: 30px;
                                                    height:30px;
                                                    background: black;
                                                    border: 2px solid black;
                                                    border-radius: 50%;
                                                    cursor: pointer;}

.slider input[type="range"]::-webkit-slider-thumb:hover {background: black;}  
)"""";

#endif
