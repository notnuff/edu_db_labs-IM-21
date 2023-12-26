/**
 * Welcome to your Workbox-powered service worker!
 *
 * You'll need to register this file in your web app and you should
 * disable HTTP caching for this file too.
 * See https://goo.gl/nhQhGp
 *
 * The rest of the code is auto-generated. Please don't update this file
 * directly; instead, make changes to your Workbox build configuration
 * and re-run your build process.
 * See https://goo.gl/2aRDsh
 */

importScripts("https://storage.googleapis.com/workbox-cdn/releases/4.3.1/workbox-sw.js");

self.addEventListener('message', (event) => {
  if (event.data && event.data.type === 'SKIP_WAITING') {
    self.skipWaiting();
  }
});

/**
 * The workboxSW.precacheAndRoute() method efficiently caches and responds to
 * requests for URLs in the manifest.
 * See https://goo.gl/S9QRab
 */
self.__precacheManifest = [
  {
    "url": "404.html",
    "revision": "0d0c6c481f31bd0900a85dafba3a5918"
  },
  {
    "url": "assets/css/0.styles.e8f8cc23.css",
    "revision": "106e99707be4f0c916857e34ee8324b7"
  },
  {
    "url": "assets/img/business_actors.541b7f52.jpg",
    "revision": "541b7f521c8d5af28423294fb1c7a3eb"
  },
  {
    "url": "assets/img/ckan.78bddb68.png",
    "revision": "78bddb68dcd27ea45b695b00956a6434"
  },
  {
    "url": "assets/img/cloude.b48a1c44.jpg",
    "revision": "b48a1c443f1f03e26e278576b8bd44ca"
  },
  {
    "url": "assets/img/comandline.b9938687.png",
    "revision": "b99386875cbd5e3e8cc3b3b1f118e6be"
  },
  {
    "url": "assets/img/create.c5629424.png",
    "revision": "c5629424a2ee628d9585165e08eab233"
  },
  {
    "url": "assets/img/crowdsourcing.abc54512.jpg",
    "revision": "abc545121419715bb1bf3e4b2de91384"
  },
  {
    "url": "assets/img/data_gov.0a1216bd.png",
    "revision": "0a1216bda60133bf7e84f798dddfbf87"
  },
  {
    "url": "assets/img/database.aba810cd.jpg",
    "revision": "aba810cd53c228329a5c00e6ee060b99"
  },
  {
    "url": "assets/img/delete.779becae.png",
    "revision": "779becae196b3296b831bb616ce8cdd0"
  },
  {
    "url": "assets/img/ERR_Diagram.eaa9b24b.png",
    "revision": "eaa9b24b80e9a9dcd975e15d9cc23b6c"
  },
  {
    "url": "assets/img/getall.c3b36757.png",
    "revision": "c3b3675744b6e2ae946049ad97559165"
  },
  {
    "url": "assets/img/getid.76ea49cd.png",
    "revision": "76ea49cd4e0307e9af2769eaf654f09d"
  },
  {
    "url": "assets/img/launch.125121d2.png",
    "revision": "125121d26236011823a891f88fa96e6b"
  },
  {
    "url": "assets/img/machine_learning.31b771f2.jpg",
    "revision": "31b771f2debbfff781cf573473788a37"
  },
  {
    "url": "assets/img/nouser.ba5f17bc.png",
    "revision": "ba5f17bc673d7c6791a9977ae44780e3"
  },
  {
    "url": "assets/img/opendatasoft.bbab4790.png",
    "revision": "bbab4790100e26097cadd67de1ddbeee"
  },
  {
    "url": "assets/img/rbac.0a226d39.jpg",
    "revision": "0a226d39b61a5e540e6d408b2e656997"
  },
  {
    "url": "assets/img/search.83621669.svg",
    "revision": "83621669651b9a3d4bf64d1a670ad856"
  },
  {
    "url": "assets/img/socrata.34930cdd.png",
    "revision": "34930cddd7c17fd3ccfce8e0a08e4cb2"
  },
  {
    "url": "assets/img/update.5b72940d.png",
    "revision": "5b72940d485b141e197c51cad18686d4"
  },
  {
    "url": "assets/img/webscrapping.688f5706.jpg",
    "revision": "688f570695020ea6ee0d402bd5542cbf"
  },
  {
    "url": "assets/img/wrongdata.c00f27bc.png",
    "revision": "c00f27bc1a53d003a6bf2ea36393f511"
  },
  {
    "url": "assets/js/1.acda8e32.js",
    "revision": "bac17ac20ff2d2931072187354844b1d"
  },
  {
    "url": "assets/js/10.1f297b1e.js",
    "revision": "1c2fdb8abfdad518206f392dd0add5c8"
  },
  {
    "url": "assets/js/13.13da8309.js",
    "revision": "5c7a4e083be62a5e374980bfd4281091"
  },
  {
    "url": "assets/js/14.057cf402.js",
    "revision": "7752f88a6ae3057011fc366e78e50506"
  },
  {
    "url": "assets/js/15.51dc31d9.js",
    "revision": "677281e9f92e7457abc40bb64aa78087"
  },
  {
    "url": "assets/js/16.f0ace81f.js",
    "revision": "c2d6e0d2cc6884ace955fb10293cde7a"
  },
  {
    "url": "assets/js/17.1c9da43b.js",
    "revision": "a9bc7593379054683aaae87556809a8f"
  },
  {
    "url": "assets/js/18.d57a843b.js",
    "revision": "0214bbf14999c72e0e82256a07b36538"
  },
  {
    "url": "assets/js/19.8c754082.js",
    "revision": "f797469cb34c455621fb42eaca5e3546"
  },
  {
    "url": "assets/js/2.bbdbe5a0.js",
    "revision": "23ba54a45ab7bd424cd040c7c9d81515"
  },
  {
    "url": "assets/js/20.b00e23c1.js",
    "revision": "0b967fb75bc41da44ea10c7f2925ca95"
  },
  {
    "url": "assets/js/21.567c67e0.js",
    "revision": "f91d71e8a29acdbb204659738752afc3"
  },
  {
    "url": "assets/js/22.9509855c.js",
    "revision": "670a8531dba75d2f13066ef07a16915f"
  },
  {
    "url": "assets/js/23.5a0f4a31.js",
    "revision": "cf2741e2a90ed09c178bcd4f6f96bb08"
  },
  {
    "url": "assets/js/24.344101b2.js",
    "revision": "49d81031cf28220cb574a52550899df9"
  },
  {
    "url": "assets/js/25.10f74ba4.js",
    "revision": "40b74abf714c5298d5cc958d677490e3"
  },
  {
    "url": "assets/js/26.6d50efb5.js",
    "revision": "1d08b73f746bcc2251dcaa5c679b57e6"
  },
  {
    "url": "assets/js/27.6d59094a.js",
    "revision": "1e91e22f00911613d9d2dbb2817a7397"
  },
  {
    "url": "assets/js/28.ad4d604f.js",
    "revision": "da9680edbf9698928b67792dccfb132e"
  },
  {
    "url": "assets/js/29.ba222f1f.js",
    "revision": "fce8488a0add772580bec72ec992a97c"
  },
  {
    "url": "assets/js/3.d7db55ae.js",
    "revision": "10f31f23ef8a9518a159d0af12392fb4"
  },
  {
    "url": "assets/js/30.9fcc299a.js",
    "revision": "51400ae22cf58cecdedaf8ef092c4418"
  },
  {
    "url": "assets/js/31.0b6e3c4d.js",
    "revision": "2d3c5b167e9ecea33a4235c82a59e3d5"
  },
  {
    "url": "assets/js/32.009d780c.js",
    "revision": "f892e5fdf247a41132ba49c19d8bade1"
  },
  {
    "url": "assets/js/33.8c09a077.js",
    "revision": "691fc3ee21ba39b66a33dd4a75249412"
  },
  {
    "url": "assets/js/34.4a393535.js",
    "revision": "f4505ec0e800d5f690b343bfd79f10e5"
  },
  {
    "url": "assets/js/35.bb17f8a5.js",
    "revision": "ebbc932f9c3a09b1272220f43c0c2894"
  },
  {
    "url": "assets/js/36.815f614b.js",
    "revision": "7c739eb8382ca570ee956620703cc7c4"
  },
  {
    "url": "assets/js/37.6dfc0064.js",
    "revision": "3645ebf3fc0f1e853934c3ffcb579d5c"
  },
  {
    "url": "assets/js/38.e7a4372b.js",
    "revision": "4853a8a2d97101daa675cc927aa9939f"
  },
  {
    "url": "assets/js/39.9dd13e89.js",
    "revision": "4c62589f2f726455bdce274f0d440960"
  },
  {
    "url": "assets/js/4.0fc3e610.js",
    "revision": "6b9c642201d6f325f32da2b76f085b4a"
  },
  {
    "url": "assets/js/41.5167c572.js",
    "revision": "fc09462c43d81c031e87c84c4693dfbf"
  },
  {
    "url": "assets/js/5.0d80563b.js",
    "revision": "ce7ffa985edff0353f9b62e1d1872eb8"
  },
  {
    "url": "assets/js/6.660206e7.js",
    "revision": "1f9cdb568016b994f9365de84fe14f18"
  },
  {
    "url": "assets/js/7.63db4d37.js",
    "revision": "5f5e64a8e1f52fb843edfa00d74fec24"
  },
  {
    "url": "assets/js/8.7740aec4.js",
    "revision": "e3e813254dbe4118374c3a53763bc1fd"
  },
  {
    "url": "assets/js/9.0d5a0b6a.js",
    "revision": "7668ef4476f618f98a408ed226472642"
  },
  {
    "url": "assets/js/app.bbee01fa.js",
    "revision": "44a92954804aa57745bcc2d8dd56bb3e"
  },
  {
    "url": "assets/js/vendors~docsearch.a7214ad1.js",
    "revision": "4fdfc9c801456fc8bade32dc84c522d5"
  },
  {
    "url": "conclusion/index.html",
    "revision": "eeacb2b1e41c5e437bd2cdc0f6ac253c"
  },
  {
    "url": "design/index.html",
    "revision": "c8eaa85e62aab1b21da0564e6462cc8d"
  },
  {
    "url": "index.html",
    "revision": "66faebb4319313992dd59a386d40b2da"
  },
  {
    "url": "intro/index.html",
    "revision": "162a3e2cc548f148494bb46272729338"
  },
  {
    "url": "license.html",
    "revision": "c6ae94487788630ac26fdec72cecb7f2"
  },
  {
    "url": "myAvatar.png",
    "revision": "b76db1e62eb8e7fca02a487eb3eac10c"
  },
  {
    "url": "requirements/index.html",
    "revision": "9f42d67ddd095bf110a3d3aee0c31b0b"
  },
  {
    "url": "requirements/stakeholders-needs.html",
    "revision": "9f9e84a0685ca3cbece5fcc5cc8bb031"
  },
  {
    "url": "requirements/state-of-the-art.html",
    "revision": "4c8ef260d18a5da68f1744b808d9322d"
  },
  {
    "url": "software/index.html",
    "revision": "6b4862aff16b21507fd63a5f50cd9c35"
  },
  {
    "url": "test/index.html",
    "revision": "ffa09532e60e31766c6c1a844e210770"
  },
  {
    "url": "use cases/index.html",
    "revision": "67b9e98b85e48e3ae4f8ffe4b594bfac"
  }
].concat(self.__precacheManifest || []);
workbox.precaching.precacheAndRoute(self.__precacheManifest, {});
addEventListener('message', event => {
  const replyPort = event.ports[0]
  const message = event.data
  if (replyPort && message && message.type === 'skip-waiting') {
    event.waitUntil(
      self.skipWaiting().then(
        () => replyPort.postMessage({ error: null }),
        error => replyPort.postMessage({ error })
      )
    )
  }
})
