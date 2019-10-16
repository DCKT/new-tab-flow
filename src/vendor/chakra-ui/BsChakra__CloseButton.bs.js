// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(color) {
  var arg = BsChakra__Types$Ext.extractProps(color, BsChakra__Types$Ext.colorToJs);
  return (function (param, param$1) {
      return (function (param$2, param$3) {
          var prim = param;
          var prim$1 = param$1;
          var prim$2 = arg;
          var prim$3 = param$2;
          var tmp = { };
          if (prim !== undefined) {
            tmp.size = (function () {
                  switch (Caml_option.valFromOption(prim)) {
                    case 25754 : 
                        return "sm";
                    case 24407 : 
                        return "md";
                    case 24187 : 
                        return "lg";
                    
                  }
                })();
          }
          if (prim$1 !== undefined) {
            tmp.isDisabled = Caml_option.valFromOption(prim$1);
          }
          if (prim$2 !== undefined) {
            tmp.color = Caml_option.valFromOption(prim$2);
          }
          if (prim$3 !== undefined) {
            tmp.key = Caml_option.valFromOption(prim$3);
          }
          return tmp;
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */