// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(size, color, name) {
  var partial_arg = BsChakra__Types$Ext.extractProps(color, BsChakra__Types$Ext.colorToJs);
  var partial_arg$1 = Belt_Option.map(name, (function (v) {
          if (v.tag) {
            return v[0];
          } else {
            return BsChakra__Types$Ext.iconToJs(v[0]);
          }
        }));
  var partial_arg$2 = BsChakra__Types$Ext.extractProps(size, (function (v) {
          return v;
        }));
  return (function (param, param$1, param$2, param$3) {
      var tmp = { };
      if (partial_arg$2 !== undefined) {
        tmp.size = Caml_option.valFromOption(partial_arg$2);
      }
      if (partial_arg$1 !== undefined) {
        tmp.name = Caml_option.valFromOption(partial_arg$1);
      }
      if (partial_arg !== undefined) {
        tmp.color = Caml_option.valFromOption(partial_arg);
      }
      if (param !== undefined) {
        tmp.focusable = Caml_option.valFromOption(param);
      }
      if (param$1 !== undefined) {
        tmp.role = (function () {
              switch (Caml_option.valFromOption(param$1)) {
                case 1040198106 : 
                    return "presentation";
                case 5245955 : 
                    return "img";
                
              }
            })();
      }
      if (param$2 !== undefined) {
        tmp.key = Caml_option.valFromOption(param$2);
      }
      return tmp;
    });
}

exports.makeProps = makeProps;
/* No side effect */
