(function(g){var window=this;'use strict';var z3=function(a){g.V.call(this,{F:"div",L:"ytp-miniplayer-ui"});this.Ve=!1;this.player=a;this.P(a,"minimized",this.dh);this.P(a,"onStateChange",this.DJ)},A3=function(a){g.YI.call(this,a);
this.j=new z3(this.player);this.j.hide();g.KI(this.player,this.j.element,4);a.uf()&&(this.load(),g.N(a.getRootNode(),"ytp-player-minimized",!0))};
g.w(z3,g.V);g.h=z3.prototype;
g.h.gH=function(){this.tooltip=new g.lN(this.player,this);g.I(this,this.tooltip);g.KI(this.player,this.tooltip.element,4);this.tooltip.scale=.6;this.Cc=new g.UJ(this.player);g.I(this,this.Cc);this.Gh=new g.V({F:"div",L:"ytp-miniplayer-scrim"});g.I(this,this.Gh);this.Gh.xa(this.element);this.P(this.Gh.element,"click",this.IC);var a=new g.V({F:"button",Ba:["ytp-miniplayer-close-button","ytp-button"],T:{"aria-label":"Zamknij"},R:[g.FG()]});g.I(this,a);a.xa(this.Gh.element);this.P(a.element,"click",this.Nj);
a=new g.IZ(this.player,this);g.I(this,a);a.xa(this.Gh.element);this.wr=new g.V({F:"div",L:"ytp-miniplayer-controls"});g.I(this,this.wr);this.wr.xa(this.Gh.element);this.P(this.wr.element,"click",this.IC);var b=new g.V({F:"div",L:"ytp-miniplayer-button-container"});g.I(this,b);b.xa(this.wr.element);a=new g.V({F:"div",L:"ytp-miniplayer-play-button-container"});g.I(this,a);a.xa(this.wr.element);var c=new g.V({F:"div",L:"ytp-miniplayer-button-container"});g.I(this,c);c.xa(this.wr.element);this.zQ=new g.JL(this.player,
this,!1);g.I(this,this.zQ);this.zQ.xa(b.element);b=new g.HL(this.player,this);g.I(this,b);b.xa(a.element);this.nextButton=new g.JL(this.player,this,!0);g.I(this,this.nextButton);this.nextButton.xa(c.element);this.Kh=new g.YM(this.player,this);g.I(this,this.Kh);this.Kh.xa(this.Gh.element);this.wc=new g.UL(this.player,this);g.I(this,this.wc);g.KI(this.player,this.wc.element,4);this.yC=new g.V({F:"div",L:"ytp-miniplayer-buttons"});g.I(this,this.yC);g.KI(this.player,this.yC.element,4);a=new g.V({F:"button",
Ba:["ytp-miniplayer-close-button","ytp-button"],T:{"aria-label":"Zamknij"},R:[g.FG()]});g.I(this,a);a.xa(this.yC.element);this.P(a.element,"click",this.Nj);a=new g.V({F:"button",Ba:["ytp-miniplayer-replay-button","ytp-button"],T:{"aria-label":"Zamknij"},R:[g.LG()]});g.I(this,a);a.xa(this.yC.element);this.P(a.element,"click",this.d_);this.P(this.player,"presentingplayerstatechange",this.Wc);this.P(this.player,"appresize",this.wb);this.P(this.player,"fullscreentoggled",this.wb);this.wb()};
g.h.show=function(){this.re=new g.Gn(this.ws,null,this);this.re.start();this.Ve||(this.gH(),this.Ve=!0);0!==this.player.getPlayerState()&&g.V.prototype.show.call(this);this.wc.show();this.player.unloadModule("annotations_module")};
g.h.hide=function(){this.re&&(this.re.dispose(),this.re=void 0);g.V.prototype.hide.call(this);this.player.uf()||(this.Ve&&this.wc.hide(),this.player.loadModule("annotations_module"))};
g.h.ea=function(){this.re&&(this.re.dispose(),this.re=void 0);g.V.prototype.ea.call(this)};
g.h.Nj=function(){this.player.stopVideo();this.player.Ma("onCloseMiniplayer")};
g.h.d_=function(){this.player.playVideo()};
g.h.IC=function(a){if(a.target===this.Gh.element||a.target===this.wr.element)this.player.S().K("kevlar_miniplayer_play_pause_on_scrim")?g.HF(this.player.xb())?this.player.pauseVideo():this.player.playVideo():this.player.Ma("onExpandMiniplayer")};
g.h.dh=function(){g.N(this.player.getRootNode(),"ytp-player-minimized",this.player.uf())};
g.h.Qd=function(){this.wc.Rb();this.Kh.Rb()};
g.h.ws=function(){this.Qd();this.re&&this.re.start()};
g.h.Wc=function(a){g.U(a.state,32)&&this.tooltip.hide()};
g.h.wb=function(){g.jM(this.wc,0,this.player.Ya().getPlayerSize().width,!1);g.XL(this.wc)};
g.h.DJ=function(a){this.player.uf()&&(0===a?this.hide():this.show())};
g.h.jc=function(){return this.tooltip};
g.h.Lf=function(){return!1};
g.h.jg=function(){return!1};
g.h.Gj=function(){return!1};
g.h.Fz=function(){};
g.h.fp=function(){};
g.h.Au=function(){};
g.h.Bp=function(){return null};
g.h.ey=function(){return null};
g.h.Ej=function(){return new g.Zk(0,0,0,0)};
g.h.handleGlobalKeyDown=function(){return!1};
g.h.handleGlobalKeyUp=function(){return!1};
g.h.Es=function(a,b,c,d,e){var f=0,k=d=0,l=g.ml(a);if(b){c=g.go(b,"ytp-prev-button")||g.go(b,"ytp-next-button");var m=g.go(b,"ytp-play-button"),n=g.go(b,"ytp-miniplayer-expand-watch-page-button");c?f=k=12:m?(b=g.kl(b,this.element),k=b.x,f=b.y-12):n&&(k=g.go(b,"ytp-miniplayer-button-top-left"),f=g.kl(b,this.element),b=g.ml(b),k?(k=8,f=f.y+40):(k=f.x-l.width+b.width,f=f.y-20))}else k=c-l.width/2,d=25+(e||0);b=this.player.Ya().getPlayerSize().width;e=f+(e||0);l=g.cg(k,0,b-l.width);e?(a.style.top=e+"px",
a.style.bottom=""):(a.style.top="",a.style.bottom=d+"px");a.style.left=l+"px"};
g.h.showControls=function(){};
g.h.Nm=function(){};
g.h.fm=function(){return!1};g.w(A3,g.YI);A3.prototype.create=function(){};
A3.prototype.ej=function(){return!1};
A3.prototype.load=function(){this.player.hideControls();this.j.show()};
A3.prototype.unload=function(){this.player.showControls();this.j.hide()};g.XI("miniplayer",A3);})(_yt_player);
