// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var BsChakra__Types$Ext = require("./BsChakra__Types.bs.js");

function makeProps(bg, color, margin, marginTop, marginBottom, marginLeft, marginRight, padding, paddingTop, paddingBottom, paddingLeft, paddingRight, px, py, maxWidth, maxHeight, width, height, flex, align, justify, direction, wrap, boxShadow, overflow, overflowX, overflowY, rounded, border) {
  var arg = Belt_Option.map(boxShadow, (function (p) {
          if (p.tag) {
            return Belt_Array.map(p[0], (function (value) {
                          if (value.tag) {
                            return value[0];
                          } else {
                            return BsChakra__Types$Ext.shadowToJs(value[0]);
                          }
                        }));
          } else {
            var v = p[0];
            if (v.tag) {
              return v[0];
            } else {
              return BsChakra__Types$Ext.shadowToJs(v[0]);
            }
          }
        }));
  var arg$1 = BsChakra__Types$Ext.mapToColor(bg);
  var arg$2 = BsChakra__Types$Ext.mapToColor(color);
  var arg$3 = BsChakra__Types$Ext.extractSpaceProps(margin);
  var arg$4 = BsChakra__Types$Ext.extractSpaceProps(marginTop);
  var arg$5 = BsChakra__Types$Ext.extractSpaceProps(marginBottom);
  var arg$6 = BsChakra__Types$Ext.extractSpaceProps(marginLeft);
  var arg$7 = BsChakra__Types$Ext.extractSpaceProps(marginRight);
  var arg$8 = BsChakra__Types$Ext.extractSpaceProps(padding);
  var arg$9 = BsChakra__Types$Ext.extractSpaceProps(paddingTop);
  var arg$10 = BsChakra__Types$Ext.extractSpaceProps(paddingBottom);
  var arg$11 = BsChakra__Types$Ext.extractSpaceProps(paddingLeft);
  var arg$12 = BsChakra__Types$Ext.extractSpaceProps(paddingRight);
  var arg$13 = BsChakra__Types$Ext.extractSpaceProps(px);
  var arg$14 = BsChakra__Types$Ext.extractSpaceProps(py);
  var arg$15 = BsChakra__Types$Ext.extractProps(direction, BsChakra__Types$Ext.flexDirectionToJs);
  var arg$16 = BsChakra__Types$Ext.extractProps(width, (function (v) {
          return v;
        }));
  var arg$17 = BsChakra__Types$Ext.extractProps(height, (function (v) {
          return v;
        }));
  var arg$18 = BsChakra__Types$Ext.extractProps(maxWidth, (function (v) {
          return v;
        }));
  var arg$19 = BsChakra__Types$Ext.extractProps(maxHeight, (function (v) {
          return v;
        }));
  var arg$20 = BsChakra__Types$Ext.extractProps(flex, (function (v) {
          return v;
        }));
  var arg$21 = BsChakra__Types$Ext.extractProps(wrap, BsChakra__Types$Ext.flexWrapToJs);
  var arg$22 = BsChakra__Types$Ext.extractProps(align, BsChakra__Types$Ext.flexAlignmentToJs);
  var arg$23 = BsChakra__Types$Ext.extractProps(justify, BsChakra__Types$Ext.flexAlignmentToJs);
  var arg$24 = BsChakra__Types$Ext.extractProps(overflow, BsChakra__Types$Ext.overflowToJs);
  var arg$25 = BsChakra__Types$Ext.extractProps(overflowX, BsChakra__Types$Ext.overflowToJs);
  var arg$26 = BsChakra__Types$Ext.extractProps(overflowY, BsChakra__Types$Ext.overflowToJs);
  var arg$27 = BsChakra__Types$Ext.extractProps(rounded, BsChakra__Types$Ext.radiiPropsToJs);
  var arg$28 = BsChakra__Types$Ext.extractBorderProps(border);
  return (function (param) {
      return (function (param$1) {
          return (function (param$2, param$3) {
              var param$4 = param$1;
              var param$5 = arg$15;
              var param$6 = arg$16;
              var param$7 = arg$17;
              var param$8 = arg$18;
              var param$9 = arg$19;
              var param$10 = arg$20;
              var param$11 = arg$21;
              var param$12 = arg$22;
              var param$13 = arg$23;
              var param$14 = arg$24;
              var param$15 = arg$25;
              var param$16 = arg$26;
              var param$17 = arg$27;
              var param$18 = arg$28;
              var param$19 = param$2;
              var param$20 = param$3;
              var prim = param;
              var prim$1 = arg;
              var prim$2 = arg$1;
              var prim$3 = arg$2;
              var prim$4 = arg$3;
              var prim$5 = arg$4;
              var prim$6 = arg$5;
              var prim$7 = arg$6;
              var prim$8 = arg$7;
              var prim$9 = arg$8;
              var prim$10 = arg$9;
              var prim$11 = arg$10;
              var prim$12 = arg$11;
              var prim$13 = arg$12;
              var prim$14 = arg$13;
              var prim$15 = arg$14;
              var prim$16 = param$4;
              var prim$17 = param$5;
              var prim$18 = param$6;
              var prim$19 = param$7;
              var prim$20 = param$8;
              var prim$21 = param$9;
              var prim$22 = param$10;
              var prim$23 = param$11;
              var prim$24 = param$12;
              var prim$25 = param$13;
              var prim$26 = param$14;
              var prim$27 = param$15;
              var prim$28 = param$16;
              var prim$29 = param$17;
              var prim$30 = param$18;
              var prim$31 = param$19;
              var tmp = {
                children: prim
              };
              if (prim$1 !== undefined) {
                tmp.boxShadow = Caml_option.valFromOption(prim$1);
              }
              if (prim$2 !== undefined) {
                tmp.bg = Caml_option.valFromOption(prim$2);
              }
              if (prim$3 !== undefined) {
                tmp.color = Caml_option.valFromOption(prim$3);
              }
              if (prim$4 !== undefined) {
                tmp.margin = Caml_option.valFromOption(prim$4);
              }
              if (prim$5 !== undefined) {
                tmp.marginTop = Caml_option.valFromOption(prim$5);
              }
              if (prim$6 !== undefined) {
                tmp.marginBottom = Caml_option.valFromOption(prim$6);
              }
              if (prim$7 !== undefined) {
                tmp.marginLeft = Caml_option.valFromOption(prim$7);
              }
              if (prim$8 !== undefined) {
                tmp.marginRight = Caml_option.valFromOption(prim$8);
              }
              if (prim$9 !== undefined) {
                tmp.padding = Caml_option.valFromOption(prim$9);
              }
              if (prim$10 !== undefined) {
                tmp.paddingTop = Caml_option.valFromOption(prim$10);
              }
              if (prim$11 !== undefined) {
                tmp.paddingBottom = Caml_option.valFromOption(prim$11);
              }
              if (prim$12 !== undefined) {
                tmp.paddingLeft = Caml_option.valFromOption(prim$12);
              }
              if (prim$13 !== undefined) {
                tmp.paddingRight = Caml_option.valFromOption(prim$13);
              }
              if (prim$14 !== undefined) {
                tmp.px = Caml_option.valFromOption(prim$14);
              }
              if (prim$15 !== undefined) {
                tmp.py = Caml_option.valFromOption(prim$15);
              }
              if (prim$16 !== undefined) {
                tmp.opacity = Caml_option.valFromOption(prim$16);
              }
              if (prim$17 !== undefined) {
                tmp.direction = Caml_option.valFromOption(prim$17);
              }
              if (prim$18 !== undefined) {
                tmp.width = Caml_option.valFromOption(prim$18);
              }
              if (prim$19 !== undefined) {
                tmp.height = Caml_option.valFromOption(prim$19);
              }
              if (prim$20 !== undefined) {
                tmp.maxWidth = Caml_option.valFromOption(prim$20);
              }
              if (prim$21 !== undefined) {
                tmp.maxHeight = Caml_option.valFromOption(prim$21);
              }
              if (prim$22 !== undefined) {
                tmp.flex = Caml_option.valFromOption(prim$22);
              }
              if (prim$23 !== undefined) {
                tmp.wrap = Caml_option.valFromOption(prim$23);
              }
              if (prim$24 !== undefined) {
                tmp.align = Caml_option.valFromOption(prim$24);
              }
              if (prim$25 !== undefined) {
                tmp.justify = Caml_option.valFromOption(prim$25);
              }
              if (prim$26 !== undefined) {
                tmp.overflow = Caml_option.valFromOption(prim$26);
              }
              if (prim$27 !== undefined) {
                tmp.overflowX = Caml_option.valFromOption(prim$27);
              }
              if (prim$28 !== undefined) {
                tmp.overflowY = Caml_option.valFromOption(prim$28);
              }
              if (prim$29 !== undefined) {
                tmp.rounded = Caml_option.valFromOption(prim$29);
              }
              if (prim$30 !== undefined) {
                tmp.border = Caml_option.valFromOption(prim$30);
              }
              if (prim$31 !== undefined) {
                tmp.key = Caml_option.valFromOption(prim$31);
              }
              return tmp;
            });
        });
    });
}

exports.makeProps = makeProps;
/* No side effect */
