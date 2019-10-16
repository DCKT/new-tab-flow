// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(size, bg) {
  var partial_arg = BsChakra__Types$Ext.extractProps(size, (function (v) {
          return v;
        }));
  var partial_arg$1 = BsChakra__Types$Ext.extractProps(bg, BsChakra__Types$Ext.colorToJs);
  return (function (param, param$1, param$2) {
      var tmp = { };
      if (partial_arg$1 !== undefined) {
        tmp.bg = Caml_option.valFromOption(partial_arg$1);
      }
      if (partial_arg !== undefined) {
        tmp.size = Caml_option.valFromOption(partial_arg);
      }
      if (param !== undefined) {
        tmp.children = Caml_option.valFromOption(param);
      }
      if (param$1 !== undefined) {
        tmp.key = Caml_option.valFromOption(param$1);
      }
      return tmp;
    });
}

exports.makeProps = makeProps;
/* No side effect */