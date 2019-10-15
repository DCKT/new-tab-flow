// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(size, width, height) {
  var arg = BsChakra__Types$Ext.extractProps(size, (function (v) {
          return v;
        }));
  var arg$1 = BsChakra__Types$Ext.extractProps(width, (function (v) {
          return v;
        }));
  var arg$2 = BsChakra__Types$Ext.extractProps(height, (function (v) {
          return v;
        }));
  return (function (param) {
      return (function (param$1, param$2) {
          return (function (param$3, param$4, param$5, param$6, param$7, param$8) {
              var param$9 = param$1;
              var param$10 = param$2;
              var param$11 = arg;
              var param$12 = arg$1;
              var param$13 = arg$2;
              var param$14 = param$3;
              var param$15 = param$4;
              var param$16 = param$5;
              var param$17 = param$6;
              var param$18 = param$7;
              var param$19 = param$8;
              var prim = param;
              var prim$1 = param$9;
              var prim$2 = param$10;
              var prim$3 = param$11;
              var prim$4 = param$12;
              var prim$5 = param$13;
              var prim$6 = param$14;
              var prim$7 = param$15;
              var prim$8 = param$16;
              var prim$9 = param$17;
              var prim$10 = param$18;
              var tmp = {
                src: prim
              };
              if (prim$1 !== undefined) {
                tmp.fallbackSrc = Caml_option.valFromOption(prim$1);
              }
              if (prim$2 !== undefined) {
                tmp.alt = Caml_option.valFromOption(prim$2);
              }
              if (prim$3 !== undefined) {
                tmp.size = Caml_option.valFromOption(prim$3);
              }
              if (prim$4 !== undefined) {
                tmp.width = Caml_option.valFromOption(prim$4);
              }
              if (prim$5 !== undefined) {
                tmp.height = Caml_option.valFromOption(prim$5);
              }
              if (prim$6 !== undefined) {
                tmp.onLoad = Caml_option.valFromOption(prim$6);
              }
              if (prim$7 !== undefined) {
                tmp.onError = Caml_option.valFromOption(prim$7);
              }
              if (prim$8 !== undefined) {
                tmp.rounded = Caml_option.valFromOption(prim$8);
              }
              if (prim$9 !== undefined) {
                tmp.objectFit = Caml_option.valFromOption(prim$9);
              }
              if (prim$10 !== undefined) {
                tmp.key = Caml_option.valFromOption(prim$10);
              }
              return tmp;
            });
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */
