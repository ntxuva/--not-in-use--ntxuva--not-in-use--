<?php
/**
 * @file
 * Front page template for Ntxuva-Mopa
 */
?>
<!--
<header role="banner" id="page-header" class="container">
  <?php print render($page['header']); ?>
</header> <!-- /#header -->

<div class="navbar-wrapper">
  <!--<div class="container">-->
    <div class="navbar navbar-inverse navbar-static-top" role="navigation">
      <div class="container-fluid">
        <div class="navbar-header">
        <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
         <?php endif; ?>

        <?php if (!empty($site_name)): ?>
          <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
          <?php endif; ?>

          <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>


        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
          <div class="collapse navbar-collapse">
            <nav role="navigation">
              <?php if (!empty($primary_nav)): ?>
                <?php print render($primary_nav); ?>
              <?php endif; ?>
              <?php if (!empty($secondary_nav)): ?>
                <?php print render($secondary_nav); ?>
              <?php endif; ?>
              <?php if (!empty($page['navigation'])): ?>
                <?php print render($page['navigation']); ?>
              <?php endif; ?>
            </nav>
          </div>
        <?php endif; ?>
      </div>
    </div>
  <!--</div>-->
</div>

<!--
<div id="map_wrapper_splash" style="display:none">
  <a id="start" title="<?php t('Click to get the map view')?>" href="/map"></a>
  <div id="map" class="front"></div>
</div>
-->
<div class="model-two padd parallax-model-two"></div>



<div class="mapheader mopathead">
  <div class="container stage">
    <div>
      <div class="col-md-12">
        <div class="welcome-text well">
          <?php
            // If you don't want bootstrap carousel to welcome visitors
            // you can use this block:
            $block = module_invoke('ntxuva_default_content', 'block_view', 'welcome');
            print render($block['content']);
          ?>
        </div>
        <div class="welcome">
          <?php
            $block = module_invoke('ntxuva_default_content', 'block_view', 'add_reports');
            print render($block['content']);
          ?>
          <?php
            $block = module_invoke('ntxuva_default_content', 'block_view', 'watch_reports');
            print render($block['content']);
          ?>
        </div>
      </div>
    </div>
  </div>
</div>
      <section>
<div class="container">
  <div class="row">
    <h2><span class="section-title">como funciona</span></h2>
   
    <hr>

    <div class="col-md-4 col-md-push-4 text-center">
    		<span><img src="profiles/ntxuva/themes/mopa/images/icon_two.png"></span>
    		<h2>Reporta</h2>
    		<p>Comunica problemas com o teu telemóvel ou através da internet</p>
    </div>

    <div class="col-md-4 col-md-pull-4 text-center">
          <span><img src="profiles/ntxuva/themes/mopa/images/icon_one.png"></span>
    		<h2>Detecta</h2>
    		<p>Fica atento à acumulação de lixo no teu bairro</p>
    </div>

    <div class="col-md-4 text-center">
    		<span><img src="profiles/ntxuva/themes/mopa/images/icon_three.png"></span>
    		<h2>Acompanha</h2>
    		<p>Visualiza a resolução de problemas através da internet</p>
    </div>
  </div>
  </div>
      </section>
      <section>
        <div class="container">
          <div class="row">
              <h2><span class="section-title">participa</span></h2>
   
    <hr>
            <div class="mt16 col-md-7">
    		<p>O mopa é uma plataforma para monitoria e avaliação dos serviços de recolha de resíduos sólidos no teu bairro.</p>
    		<p>
    		Actualmente em versão Beta, a plataforma está a funcionar em KaMavota, KaMaxaquene, KaMpfumo e Nhlhamankulo.
    		</p>
    		<p>
    		Se identificares problemas com a recolha de lixo no teu bairro, podes usar o teu computador ou celular para avisar o Conselho Municipal e as Micro-Empresas de recolha de lixo.
    		</p>
    		<p>
    		Começa já a
    		</p>
    		<div class="button-secondary">
    		<?php
            $block = module_invoke('ntxuva_default_content', 'block_view', 'add_reports');
            print render($block['content']);
          ?>
    		</div>
            </div>
            <div class="mt16 col-md-5">
              <img class="img img-responsive shadow mb16" src="profiles/ntxuva/themes/mopa/images/sec.png" style=""/>
            </div>
          </div>
        </div>
      </section>
 <section>
<div class="container">
  <div class="row">
    <h2><span class="section-title">estatísticas</span></h2>
   
    <hr>

    <div class="col-md-4 text-center">
    		<span><img src="profiles/ntxuva/themes/mopa/images/icon_four.png"></span>
    		<h2><span class="average-hours">14</span> horas</h2>
    		<p>Tempo médio para a resolução de problemas</p>
    </div>

    <div class="col-md-4 text-center">
    		<span><img src="profiles/ntxuva/themes/mopa/images/icon_five.png"></span>
    		<h2 class="frequent-request-label">Contentor cheio</h2>
    		<p>Problema mais reportado pelos utilizadores</p>
    </div>

    <div class="col-md-4 text-center">
    		<span><img src="profiles/ntxuva/themes/mopa/images/icon_six.png"></span>
    		<h2 class="frequent-location-label">Malhangalene</h2>
    		<p>Bairro mais activo a reportar os problemas</p>
    </div>
  </div>
  </div>
      </section>



<div class="container main-container">
  <div class="row">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-md-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="col-md-7">

      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header element-invisible"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <div class="well"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
<!--
      <div class="media gallery">
        <h3>
          <?php print t('Reports with Media'); ?>
        </h3>
        <?php
          $view_name = 'Gallery';
          print views_embed_view($view_name);
        ?>
      </div>
-->
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-md-4 col-md-offset-1" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
  </div>
  <div class="push"></div>
</div>

<footer class="footer">
  <?php print render($page['footer']); ?>
</footer>
