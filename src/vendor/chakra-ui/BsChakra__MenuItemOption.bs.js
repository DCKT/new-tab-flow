// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

function makeProps(value) {
  var arg = Belt_Option.map(value, (function (v) {
          return v[0];
        }));
  return (function (param, param$1, param$2) {
      return (function (param$3, param$4, param$5, param$6) {
          var prim = param;
          var prim$1 = param$1;
          var prim$2 = param$2;
          var prim$3 = arg;
          var prim$4 = param$3;
          var prim$5 = param$4;
          var prim$6 = param$5;
          var tmp = { };
          if (prim !== undefined) {
            tmp.children = Caml_option.valFromOption(prim);
          }
          if (prim$1 !== undefined) {
            tmp.isDisabled = Caml_option.valFromOption(prim$1);
          }
          if (prim$2 !== undefined) {
            tmp.type = (function () {
                  switch (Caml_option.valFromOption(prim$2)) {
                    case -468184837 : 
                        return "radio";
                    case 754307651 : 
                        return "checkbox";
                    
                  }
                })();
          }
          if (prim$3 !== undefined) {
            tmp.value = Caml_option.valFromOption(prim$3);
          }
          if (prim$4 !== undefined) {
            tmp.onMouseLeave = Caml_option.valFromOption(prim$4);
          }
          if (prim$5 !== undefined) {
            tmp.onMouseEnter = Caml_option.valFromOption(prim$5);
          }
          if (prim$6 !== undefined) {
            tmp.key = Caml_option.valFromOption(prim$6);
          }
          return tmp;
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */